int create_bitmain_turbo_mode_monitor_pthread()
{
  int v0; // r5
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  auto_freq_id = (thr_info *)calloc(1u, 0x40u);
  if ( thr_info_create(auto_freq_id, 0, (void *(*)(void *))turbo_mode_monitor, 0) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_turbo_mode_monitor_pthread");
      applog(7, tmp42, 0);
    }
    return -5;
  }
  else
  {
    pthread_detach(auto_freq_id->pth);
    cgsleep_ms(500);
    return v0;
  }
}
