void __fastcall update_work_stats(thr_info *thr, work *work)
{
  double v4; // d8
  unsigned __int64 v5; // r0
  double device_diff; // d8
  cgpu_info *cgpu; // r9
  cgpu_info *v8; // r4
  pool *pool; // r5
  _BOOL4 v10; // r6
  unsigned int v11; // r2
  const char *v12; // r2
  int *v13; // r0
  const char *v14; // r2
  int v15; // r1
  int *v16; // r0
  int v17; // r1
  const char *v18; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v4 = current_diff;
  v5 = share_diff(work);
  work->share_diff = v5;
  if ( opt_scrypt )
    v4 = v4 * 65536.0;
  if ( (double)v5 >= v4 )
  {
    pool = work->pool;
    work->block = 1;
    v10 = use_syslog;
    v11 = found_blocks + 1;
    ++pool->solved;
    found_blocks = v11;
    work->mandatory = 1;
    if ( v10 || opt_log_output || opt_log_level > 4 )
    {
      LOWORD(v12) = 1736;
      HIWORD(v12) = (unsigned int)"id nonce - HW error" >> 16;
      snprintf(tmp42, 0x1000u, v12, work->pool->pool_no);
      applog(5, tmp42, 0);
    }
  }
  if ( pthread_mutex_lock(&stats_lock) )
  {
    v13 = _errno_location();
    LOWORD(v14) = -968;
    LOWORD(v15) = -3136;
    HIWORD(v14) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v15) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v14, *v13, v15, "update_work_stats", 8383);
    goto LABEL_11;
  }
  device_diff = work->device_diff;
  cgpu = thr->cgpu;
  total_diff1 = (__int64)((double)total_diff1 + device_diff);
  cgpu->diff1 = (__int64)((double)cgpu->diff1 + device_diff);
  work->pool->diff1 = (__int64)((double)work->pool->diff1 + work->device_diff);
  v8 = thr->cgpu;
  v8->last_device_valid_work = time(0);
  if ( pthread_mutex_unlock(&stats_lock) )
  {
    v16 = _errno_location();
    LOWORD(v17) = -3136;
    LOWORD(v18) = -920;
    HIWORD(v17) = (unsigned int)"iner" >> 16;
    HIWORD(v18) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v18, *v16, v17, "update_work_stats", 8388);
LABEL_11:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
}
