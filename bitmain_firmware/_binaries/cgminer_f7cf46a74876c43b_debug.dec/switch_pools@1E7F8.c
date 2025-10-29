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
  int v16; // r3
  int v17; // r0
  pool **v18; // r1
  int v19; // r3
  int v20; // r4
  int *v21; // r0
  int *v22; // r0
  int v23; // r3
  int v24; // r4
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&control_lock.mutex) )
  {
    v19 = *_errno_location();
    v20 = 5101;
LABEL_51:
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", v19, "cgminer.c", "switch_pools", v20);
    goto LABEL_52;
  }
  v2 = pthread_rwlock_wrlock(&control_lock.rwlock);
  if ( v2 )
  {
    v21 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v21,
      "cgminer.c",
      "switch_pools",
      5101);
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
          v16 = pool_no;
          v17 = 1;
          while ( 1 )
          {
            if ( ++v16 >= total_pools )
            {
              v18 = v8;
              v16 = 0;
            }
            else
            {
              v18 = &v8[v16];
            }
            v15 = *v18;
            if ( !(*v18)->idle && v15->enabled == pool_enable::POOL_ENABLED )
              break;
            if ( ++v17 == total_pools )
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
    v22 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v22,
      "cgminer.c",
      "switch_pools",
      5163);
    goto LABEL_52;
  }
  if ( pthread_mutex_unlock(&control_lock.mutex) )
  {
    v23 = *_errno_location();
    v24 = 5163;
LABEL_56:
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", v23, "cgminer.c", "switch_pools", v24);
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
      snprintf(tmp42, 0x1000u, "Switching to pool %d %s", v15->pool_no, v15->rpc_url);
      applog(4, tmp42, 0);
    }
    clear_pool_work(v3);
  }
  if ( pthread_mutex_lock(&lp_lock) )
  {
    v19 = *_errno_location();
    v20 = 5178;
    goto LABEL_51;
  }
  pthread_cond_broadcast(&lp_cond);
  if ( pthread_mutex_unlock(&lp_lock) )
  {
    v23 = *_errno_location();
    v24 = 5180;
    goto LABEL_56;
  }
  selective_yield();
}
