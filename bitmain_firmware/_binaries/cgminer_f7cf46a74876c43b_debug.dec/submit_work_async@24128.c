void __fastcall submit_work_async(work *work)
{
  pool *pool; // r5
  cgpu_info *cgpu; // r6
  int64_t v4; // kr08_8
  double v5; // d6
  double work_difficulty; // d5
  double v7; // d7
  _BOOL4 v8; // r2
  _BOOL4 v9; // r2
  _BOOL4 stratum; // r3
  double diff_stale; // d6
  double v12; // d7
  double v13; // d5
  int v14; // r3
  int v15; // r4
  int v16; // r3
  int v17; // r4
  pthread_t submit_thread; // [sp+14h] [bp-1008h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  if ( !*(_DWORD *)&work->data[76] )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      strcpy(tmp42, "Get A Error Data To Push!DROP!\r\n");
      applog(4, tmp42, 0);
    }
    return;
  }
  pool = work->pool;
  cgtime(&work->tv_work_found);
  if ( opt_benchmark )
  {
    cgpu = get_thread(work->thr_id)->cgpu;
    if ( !pthread_mutex_lock(&stats_lock) )
    {
      v4 = total_accepted;
      ++cgpu->accepted;
      total_accepted = v4 + 1;
      v5 = total_diff_accepted;
      ++pool->accepted;
      cgpu->diff_accepted = cgpu->diff_accepted + work->work_difficulty;
      work_difficulty = work->work_difficulty;
      v7 = pool->diff_accepted + work_difficulty;
      total_diff_accepted = v5 + work_difficulty;
      pool->diff_accepted = v7;
      if ( !pthread_mutex_unlock(&stats_lock) )
      {
        selective_yield();
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "Accepted %s %d benchmark share nonce %08x",
            cgpu->drv->name,
            cgpu->device_id,
            *(_DWORD *)&work->data[76]);
          applog(7, tmp42, 0);
        }
        return;
      }
      v16 = *_errno_location();
      v17 = 8243;
      goto LABEL_65;
    }
    v14 = *_errno_location();
    v15 = 8236;
LABEL_62:
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      v14,
      "cgminer.c",
      "submit_work_async",
      v15);
    goto LABEL_63;
  }
  if ( !stale_work(work, 1) )
  {
    v8 = opt_debug;
    goto LABEL_17;
  }
  if ( !opt_submit_stale )
  {
    if ( !pool->submit_old )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "Pool %d stale share detected, discarding", pool->pool_no);
        applog(7, tmp42, 0);
      }
      sharelog("discard", work);
      if ( pthread_mutex_lock(&stats_lock) )
      {
        v14 = *_errno_location();
        v15 = 8261;
        goto LABEL_62;
      }
      diff_stale = pool->diff_stale;
      v12 = total_diff_stale;
      ++pool->stale_shares;
      v13 = work->work_difficulty;
      ++total_stale;
      pool->diff_stale = diff_stale + v13;
      total_diff_stale = v12 + v13;
      if ( pthread_mutex_unlock(&stats_lock) )
      {
        v16 = *_errno_location();
        v17 = 8266;
LABEL_65:
        snprintf(
          tmp42,
          0x1000u,
          "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
          v16,
          "cgminer.c",
          "submit_work_async",
          v17);
LABEL_63:
        applog(3, tmp42, 1);
        _quit(1, 1);
      }
      selective_yield();
LABEL_37:
      clean_work(work);
      sub_12000(work);
      return;
    }
    if ( opt_debug )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
        goto LABEL_26;
      snprintf(tmp42, 0x1000u, "Pool %d stale share detected, submitting as pool requested", pool->pool_no);
      goto LABEL_50;
    }
LABEL_51:
    stratum = work->stratum;
    work->stale = 1;
    if ( stratum )
      goto LABEL_31;
    goto LABEL_43;
  }
  if ( !opt_debug )
    goto LABEL_51;
  if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
  {
LABEL_26:
    v9 = work->stratum;
    work->stale = 1;
    if ( v9 )
    {
LABEL_27:
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        snprintf(tmp42, 0x1000u, "Pushing pool %d work to stratum queue", pool->pool_no);
        applog(7, tmp42, 0);
      }
      goto LABEL_31;
    }
LABEL_39:
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      strcpy(tmp42, "Pushing submit work to work thread");
      applog(7, tmp42, 0);
    }
    goto LABEL_43;
  }
  snprintf(tmp42, 0x1000u, "Pool %d stale share detected, submitting as user requested", pool->pool_no);
LABEL_50:
  applog(7, tmp42, 0);
  v8 = opt_debug;
  work->stale = 1;
LABEL_17:
  if ( work->stratum )
  {
    if ( v8 )
      goto LABEL_27;
LABEL_31:
    if ( tq_push(pool->stratum_q, work) )
      return;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42, "Discarding work from removed pool");
      applog(7, tmp42, 0);
    }
    goto LABEL_37;
  }
  if ( v8 )
    goto LABEL_39;
LABEL_43:
  if ( pthread_create(&submit_thread, 0, submit_work_thread, work) )
  {
    strcpy(tmp42, "Failed to create submit_work_thread");
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
}
