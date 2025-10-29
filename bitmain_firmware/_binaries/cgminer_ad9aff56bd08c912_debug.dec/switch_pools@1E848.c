void __fastcall switch_pools(pool *selected)
{
  int v2; // r6
  pool *v3; // r7
  pool_strategy v4; // r12
  int pool_no; // r10
  int prio; // r11
  int v7; // r0
  pool **v8; // lr
  pool **v9; // r2
  pool **v10; // r0
  int v11; // r1
  int v12; // t1
  int v13; // r3
  pool *v14; // r0
  pool *v15; // r5
  const char *v16; // r2
  int v17; // r3
  int v18; // r0
  pool **v19; // r1
  int *v20; // r0
  int v21; // r3
  int v22; // r1
  int v23; // r4
  const char *v24; // r2
  int *v25; // r0
  int v26; // r1
  const char *v27; // r2
  int *v28; // r0
  int v29; // r1
  const char *v30; // r2
  int *v31; // r0
  int v32; // r3
  int v33; // r1
  int v34; // r4
  const char *v35; // r2
  int *v36; // r0
  int *v37; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&control_lock.mutex) )
  {
    v20 = _errno_location();
    LOWORD(v22) = -3136;
    v21 = *v20;
    HIWORD(v22) = (unsigned int)"iner" >> 16;
    v23 = 5101;
LABEL_51:
    LOWORD(v24) = -968;
    HIWORD(v24) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v24, v21, v22, "switch_pools", v23);
    goto LABEL_52;
  }
  v2 = pthread_rwlock_wrlock(&control_lock.rwlock);
  if ( v2 )
  {
    v25 = _errno_location();
    LOWORD(v26) = -3136;
    LOWORD(v27) = -1020;
    HIWORD(v26) = (unsigned int)"iner" >> 16;
    HIWORD(v27) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v27, *v25, v26, "switch_pools", 5101);
    goto LABEL_52;
  }
  v3 = currentpool;
  v4 = pool_strategy_0;
  pool_no = currentpool->pool_no;
  if ( selected )
  {
    prio = selected->prio;
    if ( prio )
    {
      v7 = total_pools;
      if ( total_pools > 0 )
      {
        v8 = pools;
        v9 = pools;
        v10 = &pools[total_pools];
        while ( 1 )
        {
          v12 = (int)*v9++;
          v11 = v12;
          v13 = *(_DWORD *)(v12 + 4);
          if ( v13 < prio )
            *(_DWORD *)(v11 + 4) = v13 + 1;
          if ( v10 == v9 )
          {
            selected->prio = 0;
            switch ( v4 )
            {
              case pool_strategy::POOL_FAILOVER:
              case pool_strategy::POOL_LOADBALANCE:
              case pool_strategy::POOL_BALANCE:
                goto LABEL_15;
              case pool_strategy::POOL_ROUNDROBIN:
              case pool_strategy::POOL_ROTATE:
                goto LABEL_37;
              default:
                goto LABEL_49;
            }
          }
          prio = selected->prio;
        }
      }
      selected->prio = 0;
      switch ( v4 )
      {
        case pool_strategy::POOL_FAILOVER:
        case pool_strategy::POOL_LOADBALANCE:
        case pool_strategy::POOL_BALANCE:
          goto LABEL_14;
        case pool_strategy::POOL_ROUNDROBIN:
        case pool_strategy::POOL_ROTATE:
          goto LABEL_36;
        default:
          goto LABEL_30;
      }
    }
    switch ( pool_strategy_0 )
    {
      case pool_strategy::POOL_FAILOVER:
      case pool_strategy::POOL_LOADBALANCE:
      case pool_strategy::POOL_BALANCE:
        goto LABEL_13;
      case pool_strategy::POOL_ROUNDROBIN:
      case pool_strategy::POOL_ROTATE:
LABEL_36:
        v8 = pools;
LABEL_37:
        if ( selected->idle )
          goto LABEL_40;
        v15 = v8[selected->pool_no];
        break;
      default:
        goto LABEL_30;
    }
  }
  else
  {
    switch ( pool_strategy_0 )
    {
      case pool_strategy::POOL_FAILOVER:
      case pool_strategy::POOL_LOADBALANCE:
      case pool_strategy::POOL_BALANCE:
LABEL_13:
        v7 = total_pools;
LABEL_14:
        if ( v7 <= 0 )
          goto LABEL_30;
        do
        {
LABEL_15:
          v14 = priority_pool(v2);
          if ( !v14->idle && v14->enabled == pool_enable::POOL_ENABLED )
          {
            v15 = pools[v14->pool_no];
            goto LABEL_18;
          }
          ++v2;
        }
        while ( total_pools > v2 );
        v15 = pools[pool_no];
        break;
      case pool_strategy::POOL_ROUNDROBIN:
      case pool_strategy::POOL_ROTATE:
        v8 = pools;
LABEL_40:
        if ( total_pools <= 1 )
        {
LABEL_49:
          v15 = v8[pool_no];
        }
        else
        {
          v17 = pool_no;
          v18 = 1;
          while ( 1 )
          {
            if ( ++v17 >= total_pools )
            {
              v19 = v8;
              v17 = 0;
            }
            else
            {
              v19 = &v8[v17];
            }
            v15 = *v19;
            if ( !(*v19)->idle && v15->enabled == pool_enable::POOL_ENABLED )
              break;
            if ( ++v18 == total_pools )
              goto LABEL_49;
          }
        }
        break;
      default:
LABEL_30:
        v15 = pools[pool_no];
        break;
    }
  }
LABEL_18:
  currentpool = v15;
  if ( pthread_rwlock_unlock(&control_lock.rwlock) )
  {
    v28 = _errno_location();
    LOWORD(v29) = -3136;
    LOWORD(v30) = -348;
    HIWORD(v29) = (unsigned int)"iner" >> 16;
    HIWORD(v30) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    snprintf(tmp42, 0x1000u, v30, *v28, v29, "switch_pools", 5163);
    goto LABEL_52;
  }
  if ( pthread_mutex_unlock(&control_lock.mutex) )
  {
    v31 = _errno_location();
    LOWORD(v33) = -3136;
    v32 = *v31;
    HIWORD(v33) = (unsigned int)"iner" >> 16;
    v34 = 5163;
LABEL_56:
    LOWORD(v35) = -920;
    HIWORD(v35) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v35, v32, v33, "switch_pools", v34);
LABEL_52:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( opt_fail_only )
    pool_tset((int)v15, &v15->lagging);
  if ( v3 != v15 && (unsigned int)(pool_strategy_0 - 3) > 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v16) = 1844;
      HIWORD(v16) = (unsigned int)"s due to stratum disconnect on pool %d" >> 16;
      snprintf(tmp42, 0x1000u, v16, v15->pool_no, v15->rpc_url);
      applog(4, tmp42, 0);
    }
    clear_pool_work(v3);
  }
  if ( pthread_mutex_lock(&lp_lock) )
  {
    v36 = _errno_location();
    LOWORD(v22) = -3136;
    v21 = *v36;
    HIWORD(v22) = (unsigned int)"iner" >> 16;
    v23 = 5178;
    goto LABEL_51;
  }
  pthread_cond_broadcast(&lp_cond);
  if ( pthread_mutex_unlock(&lp_lock) )
  {
    v37 = _errno_location();
    LOWORD(v33) = -3136;
    v32 = *v37;
    HIWORD(v33) = (unsigned int)"iner" >> 16;
    v34 = 5180;
    goto LABEL_56;
  }
  selective_yield();
}
