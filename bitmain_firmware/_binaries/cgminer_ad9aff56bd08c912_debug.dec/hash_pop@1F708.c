work *__fastcall hash_pop(bool blocking)
{
  work *i; // r4
  int *v2; // lr
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  work *v14; // r2
  UT_hash_table *tbl; // r1
  char *prev; // r3
  ptrdiff_t hho; // r12
  UT_hash_handle *p_hh; // r0
  work *hh_next; // r1
  work *next; // r6
  UT_hash_table *v21; // r2
  int v22; // r3
  UT_hash_bucket *buckets; // r2
  UT_hash_handle *hh_head; // r6
  UT_hash_handle *hh_prev; // r2
  UT_hash_handle *v26; // r3
  int *v28; // r6
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r0
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r1
  int *v38; // r0
  const char *v39; // r2
  int v40; // r1
  int *v41; // r0
  int v42; // r1
  const char *v43; // r2
  timespec then; // [sp+10h] [bp-1014h] BYREF
  timeval now; // [sp+18h] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  i = (work *)blocking;
  if ( pthread_mutex_lock(stgd_lock) )
  {
    v38 = _errno_location();
    LOWORD(v39) = -968;
    LOWORD(v40) = -3136;
    HIWORD(v39) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v40) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v39, *v38, v40, "hash_pop", 7715);
    goto LABEL_64;
  }
  if ( staged_work && staged_work->hh.tbl->num_items )
  {
    if ( !no_work )
    {
LABEL_14:
      v14 = staged_work;
      goto LABEL_15;
    }
LABEL_40:
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v28) = 2216;
      HIWORD(v28) = (unsigned int)"for work to be available from pools." >> 16;
      v29 = *v28;
      v30 = v28[1];
      v31 = v28[2];
      v32 = v28[3];
      v28 += 4;
      *(_DWORD *)tmp42 = v29;
      *(_DWORD *)&tmp42[4] = v30;
      *(_DWORD *)&tmp42[8] = v31;
      *(_DWORD *)&tmp42[12] = v32;
      v33 = *v28;
      v34 = v28[1];
      v35 = v28[2];
      v36 = v28[3];
      v28 += 4;
      *(_DWORD *)&tmp42[16] = v33;
      *(_DWORD *)&tmp42[20] = v34;
      *(_DWORD *)&tmp42[24] = v35;
      *(_DWORD *)&tmp42[28] = v36;
      v37 = v28[1];
      *(_DWORD *)&tmp42[32] = *v28;
      tmp42[36] = v37;
      applog(4, tmp42, 0);
    }
    v14 = staged_work;
    no_work = 0;
    if ( !staged_work )
      goto LABEL_44;
LABEL_15:
    tbl = v14->hh.tbl;
    if ( (signed int)tbl->num_items > staged_rollable && !v14->clone && v14->rolltime )
    {
      for ( i = (work *)v14->hh.next; i; i = (work *)i->hh.next )
      {
        if ( i->clone || !i->rolltime )
          goto LABEL_18;
      }
LABEL_44:
      __und(0xFFu);
    }
    i = v14;
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
        v21 = hh_next->hh.tbl;
        if ( next )
        {
          *(_DWORD *)&next->data[v21->hho + 4] = i->hh.prev;
          v21 = hh_next->hh.tbl;
        }
        v22 = (v21->num_buckets - 1) & i->hh.hashv;
        --v21->buckets[v22].count;
        buckets = hh_next->hh.tbl->buckets;
        hh_head = buckets[v22].hh_head;
        if ( hh_head == p_hh )
        {
          hh_next = (work *)i->hh.hh_next;
          buckets[v22].hh_head = (UT_hash_handle *)hh_next;
        }
        hh_prev = i->hh.hh_prev;
        if ( hh_head == p_hh )
          hh_next = staged_work;
        v26 = i->hh.hh_next;
        if ( hh_prev )
        {
          hh_prev->hh_next = v26;
          v26 = i->hh.hh_next;
        }
        if ( v26 )
          v26->hh_prev = i->hh.hh_prev;
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
      hho = v14->hh.tbl->hho;
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
            LOWORD(v2) = 2168;
            HIWORD(v2) = (unsigned int)"es due to stratum disconnect on pool %d" >> 16;
            v3 = *v2;
            v4 = v2[1];
            v5 = v2[2];
            v6 = v2[3];
            v2 += 4;
            *(_DWORD *)tmp42 = v3;
            *(_DWORD *)&tmp42[4] = v4;
            *(_DWORD *)&tmp42[8] = v5;
            *(_DWORD *)&tmp42[12] = v6;
            v7 = *v2;
            v8 = v2[1];
            v9 = v2[2];
            v10 = v2[3];
            v2 += 4;
            *(_DWORD *)&tmp42[16] = v7;
            *(_DWORD *)&tmp42[20] = v8;
            *(_DWORD *)&tmp42[24] = v9;
            *(_DWORD *)&tmp42[28] = v10;
            v11 = v2[1];
            v12 = v2[2];
            v13 = v2[3];
            *(_DWORD *)&tmp42[32] = *v2;
            *(_DWORD *)&tmp42[36] = v11;
            *(_DWORD *)&tmp42[40] = v12;
            tmp42[44] = v13;
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
    v41 = _errno_location();
    LOWORD(v42) = -3136;
    LOWORD(v43) = -920;
    HIWORD(v42) = (unsigned int)"iner" >> 16;
    HIWORD(v43) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v43, *v41, v42, "hash_pop", 7782);
LABEL_64:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  return i;
}
