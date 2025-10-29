void *__fastcall __noreturn watchpool_thread(void *userdata)
{
  const char *v1; // r0
  int v2; // r3
  int v3; // r5
  pool *v4; // r4
  int64_t diff1; // r8
  double v6; // r0
  double utility; // d7
  double v8; // d6
  int prio; // r7
  const char *v10; // r2
  int v11; // r9
  list_head *next; // r1
  list_head *p_curlring; // r7
  list_head **p_prev; // r12
  int v15; // r8
  int curls; // r0
  int v17; // r2
  __int64 v18; // r2
  int v19; // r3
  int v20; // r0
  const char *v21; // r2
  int v22; // r9
  stratum_share *v23; // r7
  pool *v24; // r8
  stratum_share *v25; // r4
  char *prev; // r0
  stratum_share *v27; // r3
  UT_hash_table *tbl; // r12
  ptrdiff_t hho; // r1
  char *v30; // r0
  __int64 v31; // r0
  int v32; // r1
  UT_hash_bucket *buckets; // r0
  UT_hash_handle *hh_prev; // r1
  UT_hash_handle *hh_next; // r1
  int64_t v36; // r2
  int *v37; // r0
  const char *v38; // r2
  int v39; // r3
  const char *v40; // r4
  int *v41; // r0
  int v42; // r1
  int v43; // r3
  const char *v44; // r2
  int *v45; // r0
  int v46; // r3
  const char *v47; // r2
  int intervals; // [sp+10h] [bp-102Ch]
  pthread_mutex_t *mutex; // [sp+14h] [bp-1028h]
  pthread_mutex_t *mutexa; // [sp+14h] [bp-1028h]
  work *ptra; // [sp+1Ch] [bp-1020h]
  stratum_share *ptr; // [sp+1Ch] [bp-1020h]
  stratum_share *v53; // [sp+24h] [bp-1018h]
  timeval now; // [sp+28h] [bp-1014h] BYREF
  timeval tv; // [sp+30h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+38h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  LOWORD(v1) = 1976;
  HIWORD(v1) = (unsigned int)"ching to pool %d %s - first alive pool" >> 16;
  intervals = 0;
  RenameThread(v1);
  set_lowprio();
  while ( 1 )
  {
    v2 = intervals + 1;
    if ( intervals + 1 >= 21 )
      v2 = 0;
    intervals = v2;
    cgtime(&now);
    if ( total_pools > 0 )
      break;
LABEL_21:
    if ( current_pool()->idle )
      switch_pools(0);
    if ( pool_strategy_0 == pool_strategy::POOL_ROTATE && now.tv_sec - rotate_tv.tv_sec > 60 * opt_rotate_period )
    {
      cgtime(&rotate_tv);
      switch_pools(0);
    }
    cgsleep_ms(30000);
  }
  v3 = 0;
  while ( 1 )
  {
    v4 = pools[v3];
    if ( opt_benchmark || opt_benchfile )
      goto LABEL_10;
    mutex = &v4->pool_lock;
    cgtime(&tv);
    v11 = pthread_mutex_lock(&v4->pool_lock);
    if ( v11 )
    {
      v37 = _errno_location();
      LOWORD(v38) = -968;
      LOWORD(v39) = -3136;
      HIWORD(v38) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      HIWORD(v39) = (unsigned int)"iner" >> 16;
      snprintf(tmp42, 0x1000u, v38, *v37, v39, "reap_curl", 9503);
      goto LABEL_92;
    }
    next = v4->curlring.next;
    p_curlring = &v4->curlring;
    p_prev = &next[-1].prev;
    v15 = (int)&next->next[-1].prev;
    if ( &v4->curlring != next )
    {
      curls = v4->curls;
      if ( curls > 1 )
      {
        while ( 1 )
        {
          if ( tv.tv_sec - (int)p_prev[3] <= 300 )
          {
            v17 = *(_DWORD *)(v15 + 4) - 4;
            if ( p_curlring == (list_head *)(v15 + 4) )
              goto LABEL_40;
          }
          else
          {
            ++v11;
            v4->curls = curls - 1;
            v18 = *(_QWORD *)(p_prev + 1);
            *(_DWORD *)(v18 + 4) = HIDWORD(v18);
            *(_DWORD *)HIDWORD(v18) = v18;
            free(p_prev);
            v17 = *(_DWORD *)(v15 + 4) - 4;
            if ( p_curlring == (list_head *)(v15 + 4) )
            {
LABEL_40:
              if ( pthread_mutex_unlock(mutex) )
                goto LABEL_93;
              selective_yield();
              if ( v11 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                LOWORD(v19) = -27628;
                LOWORD(v20) = 16828;
                HIWORD(v20) = (unsigned int)"ock in recv_line" >> 16;
                LOWORD(v21) = 1988;
                if ( v11 == 1 )
                {
                  HIWORD(v19) = (unsigned int)"c.txt" >> 16;
                  v20 = v19;
                }
                HIWORD(v21) = (unsigned int)"l %d %s - first alive pool" >> 16;
                snprintf(tmp42, 0x1000u, v21, v11, v20, v4->pool_no);
                applog(7, tmp42, 0);
              }
              goto LABEL_47;
            }
          }
          curls = v4->curls;
          p_prev = (list_head **)v15;
          if ( curls <= 1 )
            goto LABEL_40;
          v15 = v17;
        }
      }
    }
    if ( pthread_mutex_unlock(mutex) )
    {
LABEL_93:
      v40 = "reap_curl";
      v41 = _errno_location();
      LOWORD(v43) = -3136;
      v42 = 9517;
      HIWORD(v43) = (unsigned int)"iner" >> 16;
      goto LABEL_94;
    }
    selective_yield();
LABEL_47:
    mutexa = (pthread_mutex_t *)time(0);
    v22 = pthread_mutex_lock(&sshare_lock);
    if ( v22 )
    {
      v45 = _errno_location();
      LOWORD(v46) = -3136;
      LOWORD(v47) = -968;
      HIWORD(v46) = (unsigned int)"iner" >> 16;
      HIWORD(v47) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v47, *v45, v46, "prune_stratum_shares", 9532);
      goto LABEL_92;
    }
    v23 = stratum_shares;
    if ( stratum_shares )
      break;
    if ( pthread_mutex_unlock(&sshare_lock) )
    {
LABEL_96:
      v41 = _errno_location();
      LOWORD(v43) = -3136;
      v40 = "prune_stratum_shares";
      HIWORD(v43) = (unsigned int)"iner" >> 16;
      v42 = 9543;
LABEL_94:
      LOWORD(v44) = -920;
      HIWORD(v44) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v44, *v41, v43, v40, v42);
LABEL_92:
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    selective_yield();
LABEL_10:
    if ( intervals == 20 )
    {
      diff1 = v4->diff1;
      v6 = (double)(diff1 - v4->last_shares);
      utility = v4->utility;
      v4->last_shares = diff1;
      v8 = (utility + v6 * 0.63) / 1.63;
      v4->utility = v8;
      v4->shares = (int)v8;
    }
    if ( v4->enabled == pool_enable::POOL_DISABLED || v4->testing )
      goto LABEL_7;
    if ( !v4->idle )
    {
LABEL_6:
      if ( pool_strategy_0 == pool_strategy::POOL_FAILOVER )
      {
        prio = v4->prio;
        if ( prio < cp_prio() && now.tv_sec - v4->tv_idle.tv_sec > 300 )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            LOWORD(v10) = 2084;
            HIWORD(v10) = (unsigned int)" stratum share response from pool %d" >> 16;
            snprintf(tmp42, 0x1000u, v10, v4->pool_no, v4->rpc_url);
            applog(4, tmp42, 0);
          }
          switch_pools(0);
        }
      }
      goto LABEL_7;
    }
    if ( now.tv_sec - v4->tv_idle.tv_sec <= 30 )
    {
LABEL_7:
      if ( total_pools <= ++v3 )
        goto LABEL_21;
    }
    else
    {
      if ( pool_active(v4, 1) && pool_tclear((int)v4, &v4->idle) )
        pool_resus(v4);
      else
        cgtime(&v4->tv_idle);
      if ( !v4->idle )
        goto LABEL_6;
      if ( total_pools <= ++v3 )
        goto LABEL_21;
    }
  }
  v24 = v4;
  v25 = (stratum_share *)stratum_shares->hh.next;
  if ( v24 == stratum_shares->work->pool )
    goto LABEL_52;
LABEL_50:
  if ( !v25 )
  {
LABEL_66:
    v4 = v24;
    if ( pthread_mutex_unlock(&sshare_lock) )
      goto LABEL_96;
    selective_yield();
    if ( v22 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "Lost %d shares due to no stratum share response from pool %d", v22, v24->pool_no);
        applog(4, tmp42, 0);
      }
      v36 = total_stale;
      v24->stale_shares += v22;
      total_stale = v36 + v22;
    }
    goto LABEL_10;
  }
  while ( 1 )
  {
    v23 = v25;
    v25 = (stratum_share *)v25->hh.next;
    if ( v24 != v23->work->pool )
      goto LABEL_50;
LABEL_52:
    if ( (int)mutexa <= v23->sshare_time + 120 )
      goto LABEL_50;
    prev = (char *)v23->hh.prev;
    v27 = stratum_shares;
    tbl = stratum_shares->hh.tbl;
    if ( prev )
      break;
    ptr = (stratum_share *)v23->hh.next;
    if ( ptr )
    {
      hho = tbl->hho;
      if ( v23 != (stratum_share *)((char *)tbl->tail - hho) )
        goto LABEL_78;
LABEL_80:
      tbl->tail = (UT_hash_handle *)&prev[hho];
      prev = (char *)v23->hh.prev;
      if ( prev )
      {
        hho = v27->hh.tbl->hho;
        goto LABEL_55;
      }
      ptr = (stratum_share *)v23->hh.next;
LABEL_78:
      v27 = ptr;
      stratum_shares = ptr;
LABEL_56:
      v30 = (char *)v23->hh.next;
      if ( v30 )
        *(_DWORD *)&v30[v27->hh.tbl->hho + 4] = v23->hh.prev;
      v31 = *(_QWORD *)&v27->hh.tbl->buckets;
      v32 = 3 * ((HIDWORD(v31) - 1) & v23->hh.hashv);
      --*(_DWORD *)(v31 + 4 * v32 + 4);
      buckets = v27->hh.tbl->buckets;
      if ( (stratum_share *)buckets[v32 / 3u].hh_head == v23 )
        buckets[v32 / 3u].hh_head = v23->hh.hh_next;
      hh_prev = v23->hh.hh_prev;
      if ( hh_prev )
        hh_prev->hh_next = v23->hh.hh_next;
      hh_next = v23->hh.hh_next;
      if ( hh_next )
        hh_next->hh_prev = v23->hh.hh_prev;
      --v27->hh.tbl->num_items;
      goto LABEL_65;
    }
    v53 = stratum_shares;
    free(tbl->buckets);
    free(v53->hh.tbl);
    stratum_shares = 0;
LABEL_65:
    ++v22;
    ptra = v23->work;
    clean_work(ptra);
    free(ptra);
    free(v23);
    if ( !v25 )
      goto LABEL_66;
  }
  hho = tbl->hho;
  if ( v23 == (stratum_share *)((char *)tbl->tail - hho) )
    goto LABEL_80;
LABEL_55:
  *(_DWORD *)&prev[hho + 8] = v23->hh.next;
  goto LABEL_56;
}
