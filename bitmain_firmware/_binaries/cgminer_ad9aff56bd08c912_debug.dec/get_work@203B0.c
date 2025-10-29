work *__fastcall get_work(thr_info *thr, const int thr_id)
{
  cgpu_info *cgpu; // r6
  int *v5; // r4
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r1
  time_t v15; // r5
  work *v16; // r4
  int v17; // r5
  _BOOL4 v18; // r3
  const char *v19; // r2
  const char *v20; // r2
  char **v21; // r3
  double *p_device_diff; // r3
  work *result; // r0
  double max_diff; // d7
  device_drv *drv; // r2
  int v26; // r1
  int hidiff; // r2
  int v28; // r2
  int v29; // r1
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  cgpu = thr->cgpu;
  thread_reportout(thr);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v5) = 2608;
    HIWORD(v5) = (unsigned int)" stale due to fail only pool mismatch" >> 16;
    v6 = *v5;
    v7 = v5[1];
    v8 = v5[2];
    v9 = v5[3];
    v5 += 4;
    *(_DWORD *)tmp42 = v6;
    *(_DWORD *)&tmp42[4] = v7;
    *(_DWORD *)&tmp42[8] = v8;
    *(_DWORD *)&tmp42[12] = v9;
    v10 = *v5;
    v11 = v5[1];
    v12 = v5[2];
    v13 = v5[3];
    v5 += 4;
    *(_DWORD *)&tmp42[16] = v10;
    *(_DWORD *)&tmp42[20] = v11;
    *(_DWORD *)&tmp42[24] = v12;
    *(_DWORD *)&tmp42[28] = v13;
    v14 = v5[1];
    *(_DWORD *)&tmp42[32] = *v5;
    *(_DWORD *)&tmp42[36] = v14;
    applog(7, tmp42, 0);
  }
  v15 = time(0);
  do
  {
    while ( 1 )
    {
      v16 = hash_pop(1);
      if ( !stale_work(v16, 0) )
        break;
      discard_work(v16);
      wake_gws();
    }
  }
  while ( !v16 );
  v17 = time(0) - v15;
  v18 = opt_debug;
  if ( v17 <= 0 )
  {
LABEL_16:
    if ( !v18 )
      goto LABEL_20;
    goto LABEL_17;
  }
  if ( !opt_debug )
  {
    cgpu->last_device_valid_work += v17;
    goto LABEL_20;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 6 )
  {
    LOWORD(v19) = 2648;
    HIWORD(v19) = (unsigned int)"Popping work from get queue to get work" >> 16;
    snprintf(tmp42, 0x1000u, v19, v17);
    applog(7, tmp42, 0);
    v18 = opt_debug;
    cgpu->last_device_valid_work += v17;
    goto LABEL_16;
  }
  cgpu->last_device_valid_work += v17;
LABEL_17:
  if ( use_syslog || opt_log_output || opt_log_level > 6 )
  {
    LOWORD(v20) = 2680;
    HIWORD(v20) = (unsigned int)"et work" >> 16;
    snprintf(tmp42, 0x1000u, v20, thr_id);
    applog(7, tmp42, 0);
  }
LABEL_20:
  v21 = &opt_logfile_path;
  v16->thr_id = thr_id;
  if ( !opt_benchmark )
    goto LABEL_21;
  v26 = cgpu->direction + cgpu->lodiff;
  cgpu->lodiff = v26;
  if ( v26 <= 0 )
  {
    cgpu->direction = 1;
LABEL_44:
    memcpy(v16, bench_lodiff_bins[v26], 0xA0u);
    goto LABEL_21;
  }
  if ( v26 <= 15 )
    goto LABEL_44;
  hidiff = cgpu->hidiff;
  cgpu->direction = -1;
  v28 = hidiff + 1;
  if ( v28 > 15 )
  {
    v29 = (int)bench_hidiff_bins;
  }
  else
  {
    v29 = 5 * v28;
    v21 = (char **)bench_hidiff_bins;
  }
  if ( v28 > 15 )
    v21 = 0;
  else
    cgpu->hidiff = v28;
  if ( v28 > 15 )
    cgpu->hidiff = (int)v21;
  else
    v29 = (int)&v21[8 * v29];
  memcpy(v16, (const void *)v29, 0xA0u);
LABEL_21:
  thread_reportin(thr);
  v16->mined = 1;
  p_device_diff = &v16->device_diff;
  result = v16;
  max_diff = cgpu->drv->max_diff;
  if ( max_diff > v16->work_difficulty )
    max_diff = v16->work_difficulty;
  *p_device_diff = max_diff;
  drv = cgpu->drv;
  if ( drv->min_diff > max_diff )
    max_diff = drv->min_diff;
  *p_device_diff = max_diff;
  return result;
}
