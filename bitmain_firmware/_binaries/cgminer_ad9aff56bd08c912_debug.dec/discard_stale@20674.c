void discard_stale()
{
  work *v0; // r4
  work *next; // r5
  int v2; // r7
  char *prev; // r1
  work *hh_next; // r2
  UT_hash_table *tbl; // lr
  ptrdiff_t hho; // r0
  UT_hash_handle *p_hh; // r12
  char *v8; // r3
  UT_hash_table *v9; // r1
  int v10; // r3
  UT_hash_bucket *buckets; // r0
  UT_hash_handle *hh_head; // r1
  bool v13; // zf
  UT_hash_handle *hh_prev; // r1
  UT_hash_handle *v15; // r3
  work *v16; // r9
  const char *v17; // r2
  int *v18; // r0
  const char *v19; // r2
  int v20; // r1
  int *v21; // r0
  int v22; // r1
  const char *v23; // r2
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(stgd_lock) )
  {
    v18 = _errno_location();
    LOWORD(v19) = -968;
    LOWORD(v20) = -3136;
    HIWORD(v19) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v20) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v19, *v18, v20, "discard_stale", 5214);
    goto LABEL_39;
  }
  v0 = staged_work;
  if ( !staged_work )
  {
    pthread_cond_signal(&gws_cond);
    if ( !pthread_mutex_unlock(stgd_lock) )
    {
      selective_yield();
      return;
    }
    goto LABEL_40;
  }
  next = (work *)staged_work->hh.next;
  v2 = 0;
  while ( 1 )
  {
    if ( !stale_work(v0, 0) )
      goto LABEL_20;
    prev = (char *)v0->hh.prev;
    hh_next = staged_work;
    tbl = staged_work->hh.tbl;
    if ( prev )
    {
      hho = tbl->hho;
      p_hh = &v0->hh;
      if ( v0 != (work *)((char *)tbl->tail - hho) )
      {
LABEL_7:
        *(_DWORD *)&prev[hho + 8] = v0->hh.next;
        v8 = (char *)v0->hh.next;
LABEL_8:
        v9 = hh_next->hh.tbl;
        if ( v8 )
        {
          *(_DWORD *)&v8[v9->hho + 4] = v0->hh.prev;
          v9 = hh_next->hh.tbl;
        }
        v10 = (v9->num_buckets - 1) & v0->hh.hashv;
        --v9->buckets[v10].count;
        buckets = hh_next->hh.tbl->buckets;
        hh_head = buckets[v10].hh_head;
        v13 = hh_head == p_hh;
        if ( hh_head == p_hh )
        {
          hh_next = (work *)v0->hh.hh_next;
          buckets[v10].hh_head = (UT_hash_handle *)hh_next;
        }
        hh_prev = v0->hh.hh_prev;
        if ( v13 )
          hh_next = staged_work;
        v15 = v0->hh.hh_next;
        if ( hh_prev )
        {
          hh_prev->hh_next = v15;
          v15 = v0->hh.hh_next;
        }
        if ( v15 )
          v15->hh_prev = v0->hh.hh_prev;
        --hh_next->hh.tbl->num_items;
        goto LABEL_19;
      }
LABEL_24:
      tbl->tail = (UT_hash_handle *)&prev[hho];
      prev = (char *)v0->hh.prev;
      if ( prev )
      {
        hho = hh_next->hh.tbl->hho;
        goto LABEL_7;
      }
      v16 = (work *)v0->hh.next;
LABEL_26:
      v8 = (char *)v16;
      hh_next = v16;
      staged_work = v16;
      goto LABEL_8;
    }
    v16 = (work *)v0->hh.next;
    if ( v16 )
    {
      hho = tbl->hho;
      p_hh = &v0->hh;
      if ( v0 != (work *)((char *)tbl->tail - hho) )
        goto LABEL_26;
      goto LABEL_24;
    }
    free(tbl->buckets);
    free(staged_work->hh.tbl);
    staged_work = 0;
LABEL_19:
    ++v2;
    discard_work(v0);
LABEL_20:
    if ( !next )
      break;
    v0 = next;
    next = (work *)next->hh.next;
  }
  pthread_cond_signal(&gws_cond);
  if ( pthread_mutex_unlock(stgd_lock) )
  {
LABEL_40:
    v21 = _errno_location();
    LOWORD(v22) = -3136;
    LOWORD(v23) = -920;
    HIWORD(v22) = (unsigned int)"iner" >> 16;
    HIWORD(v23) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v23, *v21, v22, "discard_stale", 5225);
LABEL_39:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( v2 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v17) = 2732;
    HIWORD(v17) = (unsigned int)"m get queue to get work for thread %d" >> 16;
    snprintf(tmp42, 0x1000u, v17, v2);
    applog(7, tmp42, 0);
  }
}
