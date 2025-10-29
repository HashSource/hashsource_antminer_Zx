void __fastcall clear_pool_work(pool *pool)
{
  work *v2; // r4
  int v3; // r8
  work *next; // r5
  work *hh_next; // r1
  char *prev; // r12
  UT_hash_table *tbl; // lr
  ptrdiff_t hho; // r2
  UT_hash_handle *p_hh; // r10
  char *v10; // r2
  UT_hash_table *v11; // r3
  int v12; // r2
  UT_hash_bucket *buckets; // r3
  UT_hash_handle *hh_head; // r0
  UT_hash_handle *hh_prev; // r2
  UT_hash_handle *v16; // r3
  work *v17; // r9
  int *v18; // r0
  int *v19; // r0
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( pthread_mutex_lock(stgd_lock) )
  {
    v18 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v18,
      "cgminer.c",
      "clear_pool_work",
      7016);
    goto LABEL_37;
  }
  v2 = staged_work;
  if ( !staged_work )
  {
    if ( !pthread_mutex_unlock(stgd_lock) )
    {
      selective_yield();
      return;
    }
    goto LABEL_38;
  }
  v3 = 0;
  next = (work *)staged_work->hh.next;
  if ( staged_work->pool == pool )
    goto LABEL_6;
LABEL_4:
  if ( next )
  {
    while ( 1 )
    {
      v2 = next;
      next = (work *)next->hh.next;
      if ( v2->pool != pool )
        goto LABEL_4;
LABEL_6:
      hh_next = staged_work;
      prev = (char *)v2->hh.prev;
      tbl = staged_work->hh.tbl;
      if ( prev )
        break;
      v17 = (work *)v2->hh.next;
      if ( v17 )
      {
        hho = tbl->hho;
        p_hh = &v2->hh;
        if ( v2 != (work *)((char *)tbl->tail - hho) )
          goto LABEL_33;
LABEL_31:
        tbl->tail = (UT_hash_handle *)&prev[hho];
        prev = (char *)v2->hh.prev;
        if ( !prev )
        {
          v17 = (work *)v2->hh.next;
LABEL_33:
          v10 = (char *)v17;
          hh_next = v17;
          staged_work = v17;
LABEL_9:
          v11 = hh_next->hh.tbl;
          if ( v10 )
          {
            *(_DWORD *)&v10[v11->hho + 4] = v2->hh.prev;
            v11 = hh_next->hh.tbl;
          }
          v12 = (v11->num_buckets - 1) & v2->hh.hashv;
          --v11->buckets[v12].count;
          buckets = hh_next->hh.tbl->buckets;
          hh_head = buckets[v12].hh_head;
          if ( hh_head == p_hh )
          {
            hh_next = (work *)v2->hh.hh_next;
            buckets[v12].hh_head = (UT_hash_handle *)hh_next;
          }
          hh_prev = v2->hh.hh_prev;
          if ( hh_head == p_hh )
            hh_next = staged_work;
          v16 = v2->hh.hh_next;
          if ( hh_prev )
          {
            hh_prev->hh_next = v16;
            v16 = v2->hh.hh_next;
          }
          if ( v16 )
            v16->hh_prev = v2->hh.hh_prev;
          --hh_next->hh.tbl->num_items;
          goto LABEL_20;
        }
        hho = hh_next->hh.tbl->hho;
LABEL_8:
        *(_DWORD *)&prev[hho + 8] = v2->hh.next;
        v10 = (char *)v2->hh.next;
        goto LABEL_9;
      }
      free(tbl->buckets);
      free(staged_work->hh.tbl);
      staged_work = 0;
LABEL_20:
      ++v3;
      clean_work(v2);
      free(v2);
      if ( !next )
        goto LABEL_21;
    }
    hho = tbl->hho;
    p_hh = &v2->hh;
    if ( v2 == (work *)((char *)tbl->tail - hho) )
      goto LABEL_31;
    goto LABEL_8;
  }
LABEL_21:
  if ( pthread_mutex_unlock(stgd_lock) )
  {
LABEL_38:
    v19 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v19,
      "cgminer.c",
      "clear_pool_work",
      7026);
LABEL_37:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( v3 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Cleared %d work items due to stratum disconnect on pool %d", v3, pool->pool_no);
    applog(7, tmp42, 0);
  }
}
