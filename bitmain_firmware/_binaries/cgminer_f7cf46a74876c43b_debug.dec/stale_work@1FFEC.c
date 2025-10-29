bool __fastcall stale_work(work *work, bool share)
{
  bool v2; // r5
  _BOOL4 v4; // r7
  int rolltime; // r8
  pool *pool; // r9
  int v8; // r8
  const char *v9; // r6
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int *v14; // r6
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  const char *v21; // r2
  int v22; // r3
  const char *v23; // r2
  int v24; // r3
  int *v25; // r0
  int *v26; // r0
  timeval now; // [sp+10h] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1004h] BYREF

  v2 = opt_benchmark;
  if ( !opt_benchmark )
  {
    if ( opt_benchfile )
      return v2;
    v4 = share;
    if ( work->work_block != work_block )
    {
      v2 = opt_debug;
      if ( opt_debug )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 6 )
        {
          strcpy(tmp42, "Work stale due to block mismatch");
          applog(7, tmp42, 0);
        }
        return v2;
      }
      return 1;
    }
    rolltime = work->rolltime;
    pool = work->pool;
    if ( rolltime <= opt_scantime )
      rolltime = opt_expiry;
    if ( !share && pool->has_stratum )
    {
      if ( !pool->stratum_active || !pool->stratum_notify )
      {
        v2 = opt_debug;
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          strcpy(tmp42, "Work stale due to stratum inactive");
          applog(7, tmp42, 0);
          return v2;
        }
        return 1;
      }
      if ( pthread_mutex_lock(&pool->data_lock.mutex) )
        mutex_lock((pthread_mutex_t *)&_func___15639, (const char *)0x1347, v21, v22);
      if ( pthread_rwlock_rdlock(&pool->data_lock.rwlock) )
        rd_lock((pthread_rwlock_t *)&_func___15639, (const char *)0x1347, v23, v24);
      if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
      {
        v26 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
          *v26,
          "cgminer.c",
          &_func___15639,
          4935);
LABEL_56:
        applog(3, tmp42, 1);
        _quit(1, 1);
      }
      if ( strcmp(work->job_id, pool->swork.job_id) )
      {
        if ( !pthread_rwlock_unlock(&pool->data_lock.rwlock) )
        {
          selective_yield();
          v2 = opt_debug;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            v9 = "Work stale due to stratum job_id mismatch";
            goto LABEL_42;
          }
          return 1;
        }
        goto LABEL_55;
      }
      if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
      {
LABEL_55:
        v25 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
          *v25,
          "cgminer.c",
          &_func___15639,
          4938);
        goto LABEL_56;
      }
      selective_yield();
    }
    v8 = rolltime - (int)(pool->cgminer_pool_stats.getwork_wait_rolling * 5.0 + 1.0);
    cgtime(&now);
    if ( v8 < 5 )
      v8 = 5;
    if ( v8 <= now.tv_sec - work->tv_staged.tv_sec )
    {
      v2 = opt_debug;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        strcpy(tmp42, "Work stale due to expiry");
        applog(7, tmp42, 0);
        return v2;
      }
      return 1;
    }
    if ( !opt_fail_only || v4 || pool == current_pool() || work->mandatory || (unsigned int)(pool_strategy_0 - 3) <= 1 )
      return v2;
    v2 = opt_debug;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      v9 = "Work stale due to fail only pool mismatch";
LABEL_42:
      v10 = *(_DWORD *)v9;
      v11 = *((_DWORD *)v9 + 1);
      v12 = *((_DWORD *)v9 + 2);
      v13 = *((_DWORD *)v9 + 3);
      v14 = (int *)(v9 + 16);
      *(_DWORD *)tmp42 = v10;
      *(_DWORD *)&tmp42[4] = v11;
      *(_DWORD *)&tmp42[8] = v12;
      *(_DWORD *)&tmp42[12] = v13;
      v15 = *v14;
      v16 = v14[1];
      v17 = v14[2];
      v18 = v14[3];
      v14 += 4;
      *(_DWORD *)&tmp42[16] = v15;
      *(_DWORD *)&tmp42[20] = v16;
      *(_DWORD *)&tmp42[24] = v17;
      *(_DWORD *)&tmp42[28] = v18;
      v19 = v14[1];
      v20 = v14[2];
      *(_DWORD *)&tmp42[32] = *v14;
      *(_DWORD *)&tmp42[36] = v19;
      *(_WORD *)&tmp42[40] = v20;
      applog(7, tmp42, 0);
      return v2;
    }
    return 1;
  }
  return 0;
}
