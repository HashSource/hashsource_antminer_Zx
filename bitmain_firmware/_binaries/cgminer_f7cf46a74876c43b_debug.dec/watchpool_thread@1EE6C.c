void *__fastcall __noreturn watchpool_thread(void *userdata)
{
  int v1; // r3
  int v2; // r5
  pool *v3; // r4
  int64_t diff1; // r8
  double v5; // r0
  double utility; // d7
  double v7; // d6
  int prio; // r7
  int v9; // r9
  list_head *next; // r1
  list_head *p_curlring; // r7
  list_head **p_prev; // r12
  int v13; // r8
  int curls; // r0
  int v15; // r2
  __int64 v16; // r2
  char *v17; // r0
  int v18; // r9
  stratum_share *v19; // r7
  pool *v20; // r8
  stratum_share *v21; // r4
  char *prev; // r0
  stratum_share *v23; // r3
  UT_hash_table *tbl; // r12
  ptrdiff_t hho; // r1
  char *v26; // r0
  __int64 v27; // r0
  int v28; // r1
  UT_hash_bucket *buckets; // r0
  UT_hash_handle *hh_prev; // r1
  UT_hash_handle *hh_next; // r1
  int64_t v32; // r2
  int *v33; // r0
  const char *v34; // r4
  int *v35; // r0
  int v36; // r1
  int *v37; // r0
  int intervals; // [sp+10h] [bp-102Ch]
  pthread_mutex_t *mutex; // [sp+14h] [bp-1028h]
  pthread_mutex_t *mutexa; // [sp+14h] [bp-1028h]
  work *ptra; // [sp+1Ch] [bp-1020h]
  stratum_share *ptr; // [sp+1Ch] [bp-1020h]
  stratum_share *v43; // [sp+24h] [bp-1018h]
  timeval now; // [sp+28h] [bp-1014h] BYREF
  timeval tv; // [sp+30h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+38h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  intervals = 0;
  RenameThread("Watchpool");
  set_lowprio();
  while ( 1 )
  {
    v1 = intervals + 1;
    if ( intervals + 1 >= 21 )
      v1 = 0;
    intervals = v1;
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
  v2 = 0;
  while ( 1 )
  {
    v3 = pools[v2];
    if ( opt_benchmark || opt_benchfile )
      goto LABEL_10;
    mutex = &v3->pool_lock;
    cgtime(&tv);
    v9 = pthread_mutex_lock(&v3->pool_lock);
    if ( v9 )
    {
      v33 = _errno_location();
      snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v33, "cgminer.c", "reap_curl", 9503);
      goto LABEL_92;
    }
    next = v3->curlring.next;
    p_curlring = &v3->curlring;
    p_prev = &next[-1].prev;
    v13 = (int)&next->next[-1].prev;
    if ( &v3->curlring != next )
    {
      curls = v3->curls;
      if ( curls > 1 )
      {
        while ( 1 )
        {
          if ( tv.tv_sec - (int)p_prev[3] <= 300 )
          {
            v15 = *(_DWORD *)(v13 + 4) - 4;
            if ( p_curlring == (list_head *)(v13 + 4) )
              goto LABEL_40;
          }
          else
          {
            ++v9;
            v3->curls = curls - 1;
            v16 = *(_QWORD *)(p_prev + 1);
            *(_DWORD *)(v16 + 4) = HIDWORD(v16);
            *(_DWORD *)HIDWORD(v16) = v16;
            free(p_prev);
            v15 = *(_DWORD *)(v13 + 4) - 4;
            if ( p_curlring == (list_head *)(v13 + 4) )
            {
LABEL_40:
              if ( pthread_mutex_unlock(mutex) )
                goto LABEL_93;
              selective_yield();
              if ( v9 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                v17 = "s";
                if ( v9 == 1 )
                  v17 = &byte_59398;
                snprintf(tmp42, 0x1000u, "Reaped %d curl%s from pool %d", v9, v17, v3->pool_no);
                applog(7, tmp42, 0);
              }
              goto LABEL_47;
            }
          }
          curls = v3->curls;
          p_prev = (list_head **)v13;
          if ( curls <= 1 )
            goto LABEL_40;
          v13 = v15;
        }
      }
    }
    if ( pthread_mutex_unlock(mutex) )
    {
LABEL_93:
      v34 = "reap_curl";
      v35 = _errno_location();
      v36 = 9517;
      goto LABEL_94;
    }
    selective_yield();
LABEL_47:
    mutexa = (pthread_mutex_t *)time(0);
    v18 = pthread_mutex_lock(&sshare_lock);
    if ( v18 )
    {
      v37 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
        *v37,
        "cgminer.c",
        "prune_stratum_shares",
        9532);
      goto LABEL_92;
    }
    v19 = stratum_shares;
    if ( stratum_shares )
      break;
    if ( pthread_mutex_unlock(&sshare_lock) )
    {
LABEL_96:
      v35 = _errno_location();
      v34 = "prune_stratum_shares";
      v36 = 9543;
LABEL_94:
      snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v35, "cgminer.c", v34, v36);
LABEL_92:
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    selective_yield();
LABEL_10:
    if ( intervals == 20 )
    {
      diff1 = v3->diff1;
      v5 = (double)(diff1 - v3->last_shares);
      utility = v3->utility;
      v3->last_shares = diff1;
      v7 = (utility + v5 * 0.63) / 1.63;
      v3->utility = v7;
      v3->shares = (int)v7;
    }
    if ( v3->enabled == pool_enable::POOL_DISABLED || v3->testing )
      goto LABEL_7;
    if ( !v3->idle )
    {
LABEL_6:
      if ( pool_strategy_0 == pool_strategy::POOL_FAILOVER )
      {
        prio = v3->prio;
        if ( prio < cp_prio() && now.tv_sec - v3->tv_idle.tv_sec > 300 )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            snprintf(tmp42, 0x1000u, "Pool %d %s stable for 5 mins", v3->pool_no, v3->rpc_url);
            applog(4, tmp42, 0);
          }
          switch_pools(0);
        }
      }
      goto LABEL_7;
    }
    if ( now.tv_sec - v3->tv_idle.tv_sec <= 30 )
    {
LABEL_7:
      if ( total_pools <= ++v2 )
        goto LABEL_21;
    }
    else
    {
      if ( pool_active(v3, 1) && pool_tclear((int)v3, &v3->idle) )
        pool_resus(v3);
      else
        cgtime(&v3->tv_idle);
      if ( !v3->idle )
        goto LABEL_6;
      if ( total_pools <= ++v2 )
        goto LABEL_21;
    }
  }
  v20 = v3;
  v21 = (stratum_share *)stratum_shares->hh.next;
  if ( v20 == stratum_shares->work->pool )
    goto LABEL_52;
LABEL_50:
  if ( !v21 )
  {
LABEL_66:
    v3 = v20;
    if ( pthread_mutex_unlock(&sshare_lock) )
      goto LABEL_96;
    selective_yield();
    if ( v18 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "Lost %d shares due to no stratum share response from pool %d", v18, v20->pool_no);
        applog(4, tmp42, 0);
      }
      v32 = total_stale;
      v20->stale_shares += v18;
      total_stale = v32 + v18;
    }
    goto LABEL_10;
  }
  while ( 1 )
  {
    v19 = v21;
    v21 = (stratum_share *)v21->hh.next;
    if ( v20 != v19->work->pool )
      goto LABEL_50;
LABEL_52:
    if ( (int)mutexa <= v19->sshare_time + 120 )
      goto LABEL_50;
    prev = (char *)v19->hh.prev;
    v23 = stratum_shares;
    tbl = stratum_shares->hh.tbl;
    if ( prev )
      break;
    ptr = (stratum_share *)v19->hh.next;
    if ( ptr )
    {
      hho = tbl->hho;
      if ( v19 != (stratum_share *)((char *)tbl->tail - hho) )
        goto LABEL_78;
LABEL_80:
      tbl->tail = (UT_hash_handle *)&prev[hho];
      prev = (char *)v19->hh.prev;
      if ( prev )
      {
        hho = v23->hh.tbl->hho;
        goto LABEL_55;
      }
      ptr = (stratum_share *)v19->hh.next;
LABEL_78:
      v23 = ptr;
      stratum_shares = ptr;
LABEL_56:
      v26 = (char *)v19->hh.next;
      if ( v26 )
        *(_DWORD *)&v26[v23->hh.tbl->hho + 4] = v19->hh.prev;
      v27 = *(_QWORD *)&v23->hh.tbl->buckets;
      v28 = 3 * ((HIDWORD(v27) - 1) & v19->hh.hashv);
      --*(_DWORD *)(v27 + 4 * v28 + 4);
      buckets = v23->hh.tbl->buckets;
      if ( (stratum_share *)buckets[v28 / 3u].hh_head == v19 )
        buckets[v28 / 3u].hh_head = v19->hh.hh_next;
      hh_prev = v19->hh.hh_prev;
      if ( hh_prev )
        hh_prev->hh_next = v19->hh.hh_next;
      hh_next = v19->hh.hh_next;
      if ( hh_next )
        hh_next->hh_prev = v19->hh.hh_prev;
      --v23->hh.tbl->num_items;
      goto LABEL_65;
    }
    v43 = stratum_shares;
    free(tbl->buckets);
    free(v43->hh.tbl);
    stratum_shares = 0;
LABEL_65:
    ++v18;
    ptra = v19->work;
    clean_work(ptra);
    free(ptra);
    free(v19);
    if ( !v21 )
      goto LABEL_66;
  }
  hho = tbl->hho;
  if ( v19 == (stratum_share *)((char *)tbl->tail - hho) )
    goto LABEL_80;
LABEL_55:
  *(_DWORD *)&prev[hho + 8] = v19->hh.next;
  goto LABEL_56;
}
