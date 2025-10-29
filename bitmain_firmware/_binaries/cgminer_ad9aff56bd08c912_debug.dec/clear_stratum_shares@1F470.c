void __fastcall clear_stratum_shares(pool *pool)
{
  stratum_share *v2; // r4
  int v3; // r8
  stratum_share *next; // r5
  double v5; // d8
  char *prev; // r0
  stratum_share *v7; // r7
  UT_hash_table *tbl; // r12
  ptrdiff_t hho; // r2
  char *v10; // r2
  UT_hash_table *v11; // r1
  int v12; // r2
  UT_hash_bucket *buckets; // r1
  UT_hash_handle *hh_next; // r2
  UT_hash_handle *hh_prev; // r3
  work *work; // r7
  double v17; // d6
  double v18; // d8
  int64_t v19; // kr10_8
  unsigned int v20; // r4
  stratum_share *v21; // r1
  int *v22; // r0
  const char *v23; // r2
  int v24; // r1
  int *v25; // r0
  int v26; // r1
  const char *v27; // r2
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  if ( pthread_mutex_lock(&sshare_lock) )
  {
    v22 = _errno_location();
    LOWORD(v23) = -968;
    LOWORD(v24) = -3136;
    HIWORD(v23) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v24) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v23, *v22, v24, "clear_stratum_shares", 6986);
    goto LABEL_36;
  }
  v2 = stratum_shares;
  if ( !stratum_shares )
  {
    if ( !pthread_mutex_unlock(&sshare_lock) )
    {
      selective_yield();
      return;
    }
    goto LABEL_37;
  }
  v3 = 0;
  next = (stratum_share *)stratum_shares->hh.next;
  v5 = 0.0;
  if ( stratum_shares->work->pool == pool )
    goto LABEL_6;
LABEL_4:
  if ( next )
  {
    while ( 1 )
    {
      v2 = next;
      next = (stratum_share *)next->hh.next;
      if ( v2->work->pool != pool )
        goto LABEL_4;
LABEL_6:
      prev = (char *)v2->hh.prev;
      v7 = stratum_shares;
      tbl = stratum_shares->hh.tbl;
      if ( prev )
        break;
      v21 = (stratum_share *)v2->hh.next;
      if ( v21 )
      {
        hho = tbl->hho;
        if ( v2 != (stratum_share *)((char *)tbl->tail - hho) )
          goto LABEL_30;
LABEL_28:
        tbl->tail = (UT_hash_handle *)&prev[hho];
        prev = (char *)v2->hh.prev;
        if ( !prev )
        {
          v21 = (stratum_share *)v2->hh.next;
LABEL_30:
          v10 = (char *)v21;
          v7 = v21;
          stratum_shares = v21;
LABEL_9:
          v11 = v7->hh.tbl;
          if ( v10 )
          {
            *(_DWORD *)&v10[v11->hho + 4] = v2->hh.prev;
            v11 = v7->hh.tbl;
          }
          v12 = (v11->num_buckets - 1) & v2->hh.hashv;
          --v11->buckets[v12].count;
          buckets = v7->hh.tbl->buckets;
          if ( (stratum_share *)buckets[v12].hh_head == v2 )
            buckets[v12].hh_head = v2->hh.hh_next;
          hh_next = v2->hh.hh_next;
          hh_prev = v2->hh.hh_prev;
          if ( hh_prev )
          {
            hh_prev->hh_next = hh_next;
            hh_next = v2->hh.hh_next;
          }
          if ( hh_next )
            hh_next->hh_prev = v2->hh.hh_prev;
          --v7->hh.tbl->num_items;
          goto LABEL_18;
        }
        hho = v7->hh.tbl->hho;
LABEL_8:
        *(_DWORD *)&prev[hho + 8] = v2->hh.next;
        v10 = (char *)v2->hh.next;
        goto LABEL_9;
      }
      free(tbl->buckets);
      free(v7->hh.tbl);
      stratum_shares = 0;
LABEL_18:
      work = v2->work;
      ++v3;
      v5 = v5 + work->work_difficulty;
      clean_work(work);
      free(work);
      v2->work = 0;
      --pool->sshares;
      free(v2);
      if ( !next )
        goto LABEL_19;
    }
    hho = tbl->hho;
    if ( v2 == (stratum_share *)((char *)tbl->tail - hho) )
      goto LABEL_28;
    goto LABEL_8;
  }
LABEL_19:
  if ( pthread_mutex_unlock(&sshare_lock) )
  {
LABEL_37:
    v25 = _errno_location();
    LOWORD(v26) = -3136;
    LOWORD(v27) = -920;
    HIWORD(v26) = (unsigned int)"iner" >> 16;
    HIWORD(v27) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v27, *v25, v26, "clear_stratum_shares", 6999);
LABEL_36:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( v3 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      snprintf(tmp42, 0x1000u, "Lost %d shares due to stratum disconnect on pool %d", v3, pool->pool_no);
      applog(4, tmp42, 0);
    }
    v17 = pool->diff_stale + v5;
    v18 = total_diff_stale + v5;
    v19 = total_stale + v3;
    v20 = pool->stale_shares + v3;
    pool->diff_stale = v17;
    total_stale = v19;
    pool->stale_shares = v20;
    total_diff_stale = v18;
  }
}
