bool __fastcall stale_work(work *work, bool share)
{
  bool v2; // r5
  _BOOL4 v4; // r7
  int *v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int rolltime; // r8
  pool *pool; // r9
  int *v18; // r6
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r0
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r6
  int v28; // r8
  int *v29; // r6
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r2
  int *v36; // r6
  int v37; // r0
  int v38; // r1
  int v39; // r2
  int v40; // r3
  int *v41; // r6
  int v42; // r0
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r1
  int v47; // r2
  const char *v48; // r2
  int v49; // r3
  const char *v50; // r2
  int v51; // r3
  int *v52; // r0
  const char *v53; // r2
  int v54; // r3
  int *v55; // r0
  int v56; // r3
  const char *v57; // r2
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
          LOWORD(v6) = 2420;
          HIWORD(v6) = (unsigned int)"id %s, nonce1 %s, nonce2 %llu, ntime %s" >> 16;
          v7 = *v6;
          v8 = v6[1];
          v9 = v6[2];
          v10 = v6[3];
          v6 += 4;
          *(_DWORD *)tmp42 = v7;
          *(_DWORD *)&tmp42[4] = v8;
          *(_DWORD *)&tmp42[8] = v9;
          *(_DWORD *)&tmp42[12] = v10;
          v11 = *v6;
          v12 = v6[1];
          v13 = v6[2];
          v14 = v6[3];
          v15 = v6[4];
          *(_DWORD *)&tmp42[16] = v11;
          *(_DWORD *)&tmp42[20] = v12;
          *(_DWORD *)&tmp42[24] = v13;
          *(_DWORD *)&tmp42[28] = v14;
          tmp42[32] = v15;
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
          LOWORD(v18) = 2456;
          HIWORD(v18) = (unsigned int)" %s" >> 16;
          v19 = *v18;
          v20 = v18[1];
          v21 = v18[2];
          v22 = v18[3];
          v18 += 4;
          *(_DWORD *)tmp42 = v19;
          *(_DWORD *)&tmp42[4] = v20;
          *(_DWORD *)&tmp42[8] = v21;
          *(_DWORD *)&tmp42[12] = v22;
          v23 = *v18;
          v24 = v18[1];
          v25 = v18[2];
          v26 = v18[3];
          v27 = v18[4];
          *(_DWORD *)&tmp42[16] = v23;
          *(_DWORD *)&tmp42[20] = v24;
          *(_DWORD *)&tmp42[24] = v25;
          *(_DWORD *)&tmp42[28] = v26;
          *(_WORD *)&tmp42[32] = v27;
          tmp42[34] = BYTE2(v27);
          applog(7, tmp42, 0);
          return v2;
        }
        return 1;
      }
      if ( pthread_mutex_lock(&pool->data_lock.mutex) )
        mutex_lock((pthread_mutex_t *)&_func___15639, (const char *)0x1347, v48, v49);
      if ( pthread_rwlock_rdlock(&pool->data_lock.rwlock) )
        rd_lock((pthread_rwlock_t *)&_func___15639, (const char *)0x1347, v50, v51);
      if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
      {
        v55 = _errno_location();
        LOWORD(v56) = -3136;
        LOWORD(v57) = -920;
        HIWORD(v56) = (unsigned int)"iner" >> 16;
        HIWORD(v57) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
        snprintf(tmp42, 0x1000u, v57, *v55, v56, &_func___15639, 4935);
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
            LOWORD(v36) = 2492;
            HIWORD(v36) = (unsigned int)"" >> 16;
            goto LABEL_42;
          }
          return 1;
        }
        goto LABEL_55;
      }
      if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
      {
LABEL_55:
        v52 = _errno_location();
        LOWORD(v53) = -348;
        LOWORD(v54) = -3136;
        HIWORD(v53) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
        HIWORD(v54) = (unsigned int)"iner" >> 16;
        snprintf(tmp42, 0x1000u, v53, *v52, v54, &_func___15639, 4938);
        goto LABEL_56;
      }
      selective_yield();
    }
    v28 = rolltime - (int)(pool->cgminer_pool_stats.getwork_wait_rolling * 5.0 + 1.0);
    cgtime(&now);
    if ( v28 < 5 )
      v28 = 5;
    if ( v28 <= now.tv_sec - work->tv_staged.tv_sec )
    {
      v2 = opt_debug;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v29) = 2536;
        HIWORD(v29) = (unsigned int)" stale due to stratum job_id mismatch" >> 16;
        v30 = *v29;
        v31 = v29[1];
        v32 = v29[2];
        v33 = v29[3];
        v29 += 4;
        *(_DWORD *)tmp42 = v30;
        *(_DWORD *)&tmp42[4] = v31;
        *(_DWORD *)&tmp42[8] = v32;
        *(_DWORD *)&tmp42[12] = v33;
        v34 = v29[1];
        v35 = v29[2];
        *(_DWORD *)&tmp42[16] = *v29;
        *(_DWORD *)&tmp42[20] = v34;
        tmp42[24] = v35;
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
      LOWORD(v36) = 2564;
      HIWORD(v36) = (unsigned int)" mismatch" >> 16;
LABEL_42:
      v37 = *v36;
      v38 = v36[1];
      v39 = v36[2];
      v40 = v36[3];
      v41 = v36 + 4;
      *(_DWORD *)tmp42 = v37;
      *(_DWORD *)&tmp42[4] = v38;
      *(_DWORD *)&tmp42[8] = v39;
      *(_DWORD *)&tmp42[12] = v40;
      v42 = *v41;
      v43 = v41[1];
      v44 = v41[2];
      v45 = v41[3];
      v41 += 4;
      *(_DWORD *)&tmp42[16] = v42;
      *(_DWORD *)&tmp42[20] = v43;
      *(_DWORD *)&tmp42[24] = v44;
      *(_DWORD *)&tmp42[28] = v45;
      v46 = v41[1];
      v47 = v41[2];
      *(_DWORD *)&tmp42[32] = *v41;
      *(_DWORD *)&tmp42[36] = v46;
      *(_WORD *)&tmp42[40] = v47;
      applog(7, tmp42, 0);
      return v2;
    }
    return 1;
  }
  return 0;
}
