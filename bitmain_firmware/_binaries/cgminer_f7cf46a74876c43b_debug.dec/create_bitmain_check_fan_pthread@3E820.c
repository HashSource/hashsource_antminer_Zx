int create_bitmain_check_fan_pthread()
{
  int v0; // r5
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  check_fan_id = (thr_info *)calloc(1u, 0x40u);
  if ( thr_info_create(check_fan_id, 0, (void *(*)(void *))check_fan_thr, 0) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_check_fan_pthread");
      applog(7, tmp42, 0);
    }
    return -8;
  }
  else
  {
    pthread_detach(check_fan_id->pth);
    cgsleep_ms(500);
    return v0;
  }
}
