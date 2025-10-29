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
  int *v12; // r0
  int *v13; // r0
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
      snprintf(tmp42, 0x1000u, "Found block for pool %d!", work->pool->pool_no);
      applog(5, tmp42, 0);
    }
  }
  if ( pthread_mutex_lock(&stats_lock) )
  {
    v12 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v12,
      "cgminer.c",
      "update_work_stats",
      8383);
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
    v13 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v13,
      "cgminer.c",
      "update_work_stats",
      8388);
LABEL_11:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
}
