work *__fastcall get_work(thr_info *thr, const int thr_id)
{
  cgpu_info *cgpu; // r6
  time_t v5; // r5
  work *v6; // r4
  int v7; // r5
  _BOOL4 v8; // r3
  char **v9; // r3
  double *p_device_diff; // r3
  work *result; // r0
  double max_diff; // d7
  device_drv *drv; // r2
  int v14; // r1
  int hidiff; // r2
  int v16; // r2
  int v17; // r1
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  cgpu = thr->cgpu;
  thread_reportout(thr);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Popping work from get queue to get work");
    applog(7, tmp42, 0);
  }
  v5 = time(0);
  do
  {
    while ( 1 )
    {
      v6 = hash_pop(1);
      if ( !stale_work(v6, 0) )
        break;
      discard_work(v6);
      wake_gws();
    }
  }
  while ( !v6 );
  v7 = time(0) - v5;
  v8 = opt_debug;
  if ( v7 <= 0 )
  {
LABEL_16:
    if ( !v8 )
      goto LABEL_20;
    goto LABEL_17;
  }
  if ( !opt_debug )
  {
    cgpu->last_device_valid_work += v7;
    goto LABEL_20;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 6 )
  {
    snprintf(tmp42, 0x1000u, "Get work blocked for %d seconds", v7);
    applog(7, tmp42, 0);
    v8 = opt_debug;
    cgpu->last_device_valid_work += v7;
    goto LABEL_16;
  }
  cgpu->last_device_valid_work += v7;
LABEL_17:
  if ( use_syslog || opt_log_output || opt_log_level > 6 )
  {
    snprintf(tmp42, 0x1000u, "Got work from get queue to get work for thread %d", thr_id);
    applog(7, tmp42, 0);
  }
LABEL_20:
  v9 = &opt_logfile_path;
  v6->thr_id = thr_id;
  if ( !opt_benchmark )
    goto LABEL_21;
  v14 = cgpu->direction + cgpu->lodiff;
  cgpu->lodiff = v14;
  if ( v14 <= 0 )
  {
    cgpu->direction = 1;
LABEL_44:
    memcpy(v6, bench_lodiff_bins[v14], 0xA0u);
    goto LABEL_21;
  }
  if ( v14 <= 15 )
    goto LABEL_44;
  hidiff = cgpu->hidiff;
  cgpu->direction = -1;
  v16 = hidiff + 1;
  if ( v16 > 15 )
  {
    v17 = (int)bench_hidiff_bins;
  }
  else
  {
    v17 = 5 * v16;
    v9 = (char **)bench_hidiff_bins;
  }
  if ( v16 > 15 )
    v9 = 0;
  else
    cgpu->hidiff = v16;
  if ( v16 > 15 )
    cgpu->hidiff = (int)v9;
  else
    v17 = (int)&v9[8 * v17];
  memcpy(v6, (const void *)v17, 0xA0u);
LABEL_21:
  thread_reportin(thr);
  v6->mined = 1;
  p_device_diff = &v6->device_diff;
  result = v6;
  max_diff = cgpu->drv->max_diff;
  if ( max_diff > v6->work_difficulty )
    max_diff = v6->work_difficulty;
  *p_device_diff = max_diff;
  drv = cgpu->drv;
  if ( drv->min_diff > max_diff )
    max_diff = drv->min_diff;
  *p_device_diff = max_diff;
  return result;
}
