void __fastcall inc_hw_errors_with_diff(thr_info *thr, int diff)
{
  cgpu_info *cgpu; // r6
  int v5; // r1
  int *v6; // r0
  int *v7; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "%s%d: invalid nonce - HW error", thr->cgpu->drv->name, thr->cgpu->device_id);
    applog(7, tmp42, 0);
  }
  if ( pthread_mutex_lock(&stats_lock) )
  {
    v6 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v6,
      "cgminer.c",
      &_func___16209.__align + 5,
      8309);
    goto LABEL_11;
  }
  cgpu = thr->cgpu;
  v5 = cgpu->hw_errors + diff;
  hw_errors += diff;
  cgpu->hw_errors = v5;
  if ( pthread_mutex_unlock(&stats_lock) )
  {
    v7 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v7,
      "cgminer.c",
      &_func___16209.__align + 5,
      8312);
LABEL_11:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  thr->cgpu->drv->hw_error(thr);
}
