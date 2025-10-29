work *__fastcall hash_pop(bool blocking)
{
  work *i; // r4
  work *v2; // r2
  UT_hash_table *tbl; // r1
  char *prev; // r3
  ptrdiff_t hho; // r12
  UT_hash_handle *p_hh; // r0
  work *hh_next; // r1
  work *next; // r6
  UT_hash_table *v9; // r2
  int v10; // r3
  UT_hash_bucket *buckets; // r2
  UT_hash_handle *hh_head; // r6
  UT_hash_handle *hh_prev; // r2
  UT_hash_handle *v14; // r3
  int *v16; // r0
  int *v17; // r0
  timespec then; // [sp+10h] [bp-1014h] BYREF
  timeval now; // [sp+18h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  i = (work *)blocking;
  if ( pthread_mutex_lock(stgd_lock) )
  {
    v16 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v16, "cgminer.c", "hash_pop", 7715);
    goto LABEL_64;
  }
  if ( staged_work && staged_work->hh.tbl->num_items )
  {
    if ( !no_work )
    {
LABEL_14:
      v2 = staged_work;
      goto LABEL_15;
    }
LABEL_40:
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      strcpy(tmp42, "Work available from pools, resuming.");
      applog(4, tmp42, 0);
    }
    v2 = staged_work;
    no_work = 0;
    if ( !staged_work )
      goto LABEL_44;
LABEL_15:
    tbl = v2->hh.tbl;
    if ( (signed int)tbl->num_items > staged_rollable && !v2->clone && v2->rolltime )
    {
      for ( i = (work *)v2->hh.next; i; i = (work *)i->hh.next )
      {
        if ( i->clone || !i->rolltime )
          goto LABEL_18;
      }
LABEL_44:
      __und(0xFFu);
    }
    i = v2;
LABEL_18:
    prev = (char *)i->hh.prev;
    if ( prev )
    {
      hho = tbl->hho;
      p_hh = &i->hh;
      if ( i != (work *)((char *)tbl->tail - hho) )
      {
LABEL_20:
        hh_next = staged_work;
        *(_DWORD *)&prev[hho + 8] = i->hh.next;
        next = (work *)i->hh.next;
LABEL_21:
        v9 = hh_next->hh.tbl;
        if ( next )
        {
          *(_DWORD *)&next->data[v9->hho + 4] = i->hh.prev;
          v9 = hh_next->hh.tbl;
        }
        v10 = (v9->num_buckets - 1) & i->hh.hashv;
        --v9->buckets[v10].count;
        buckets = hh_next->hh.tbl->buckets;
        hh_head = buckets[v10].hh_head;
        if ( hh_head == p_hh )
        {
          hh_next = (work *)i->hh.hh_next;
          buckets[v10].hh_head = (UT_hash_handle *)hh_next;
        }
        hh_prev = i->hh.hh_prev;
        if ( hh_head == p_hh )
          hh_next = staged_work;
        v14 = i->hh.hh_next;
        if ( hh_prev )
        {
          hh_prev->hh_next = v14;
          v14 = i->hh.hh_next;
        }
        if ( v14 )
          v14->hh_prev = i->hh.hh_prev;
        --hh_next->hh.tbl->num_items;
        goto LABEL_32;
      }
    }
    else
    {
      next = (work *)i->hh.next;
      if ( !next )
      {
        free(tbl->buckets);
        free(staged_work->hh.tbl);
        staged_work = 0;
LABEL_32:
        if ( !i->clone && i->rolltime )
          --staged_rollable;
        pthread_cond_signal(&gws_cond);
        pthread_cond_signal(&getq->cond);
        last_getwork = time(0);
        goto out_unlock;
      }
      hho = tbl->hho;
      p_hh = &i->hh;
      if ( i != (work *)((char *)tbl->tail - hho) )
        goto LABEL_52;
    }
    tbl->tail = (UT_hash_handle *)&prev[hho];
    prev = (char *)i->hh.prev;
    if ( prev )
    {
      hho = v2->hh.tbl->hho;
      goto LABEL_20;
    }
    next = (work *)i->hh.next;
LABEL_52:
    hh_next = next;
    staged_work = next;
    goto LABEL_21;
  }
  if ( work_filled && max_queue < opt_queue )
  {
    ++max_queue;
    work_filled = 0;
  }
  work_emptied = 1;
  if ( i )
  {
    do
    {
      cgtime(&now);
      then.tv_sec = now.tv_sec + 10;
      then.tv_nsec = 1000 * now.tv_usec;
      pthread_cond_signal(&gws_cond);
      if ( pthread_cond_timedwait(&getq->cond, stgd_lock, &then) )
      {
        if ( !no_work )
        {
          no_work = 1;
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            strcpy(tmp42, "Waiting for work to be available from pools.");
            applog(4, tmp42, 0);
          }
        }
      }
    }
    while ( !staged_work || !staged_work->hh.tbl->num_items );
    if ( !no_work )
      goto LABEL_14;
    goto LABEL_40;
  }
out_unlock:
  if ( pthread_mutex_unlock(stgd_lock) )
  {
    v17 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v17, "cgminer.c", "hash_pop", 7782);
LABEL_64:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  return i;
}
