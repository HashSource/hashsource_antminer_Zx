void __fastcall inc_hw_errors(thr_info *thr)
{
  cgpu_info *cgpu; // r5
  int v3; // r2
  int *v4; // r0
  const char *v5; // r2
  int v6; // r1
  int *v7; // r0
  int v8; // r1
  const char *v9; // r2
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "%s %d: invalid nonce - HW error", thr->cgpu->drv->name, thr->cgpu->device_id);
    applog(7, tmp42, 1);
  }
  if ( pthread_mutex_lock(&stats_lock) )
  {
    v4 = _errno_location();
    LOWORD(v5) = -968;
    LOWORD(v6) = -3136;
    HIWORD(v5) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v6) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v5, *v4, v6, "inc_hw_errors", 8296);
    goto LABEL_11;
  }
  cgpu = thr->cgpu;
  v3 = cgpu->hw_errors + 1;
  ++hw_errors;
  cgpu->hw_errors = v3;
  if ( pthread_mutex_unlock(&stats_lock) )
  {
    v7 = _errno_location();
    LOWORD(v8) = -3136;
    LOWORD(v9) = -920;
    HIWORD(v8) = (unsigned int)"iner" >> 16;
    HIWORD(v9) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v9, *v7, v8, "inc_hw_errors", 8299);
LABEL_11:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  thr->cgpu->drv->hw_error(thr);
}
