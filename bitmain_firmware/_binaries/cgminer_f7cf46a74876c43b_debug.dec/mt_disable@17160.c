// Alternative name is 'mt_disable.isra.19'
void __fastcall mt_disable(thr_info *mythr, int thr_id, device_drv *drv)
{
  _BOOL4 v6; // r3
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42, 0x1000u, "Thread %d being disabled", thr_id);
    applog(4, tmp42, 0);
  }
  v6 = opt_debug;
  mythr->cgpu->rolling = 0.0;
  if ( v6 && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Waiting on sem in miner thread");
    applog(7, tmp42, 0);
  }
  cgsem_wait(&mythr->sem, "cgminer.c", "mt_disable", 8561);
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42, 0x1000u, "Thread %d being re-enabled", thr_id);
    applog(4, tmp42, 0);
  }
  ((void (__fastcall *)(thr_info *))drv->drv_id)(mythr);
}
