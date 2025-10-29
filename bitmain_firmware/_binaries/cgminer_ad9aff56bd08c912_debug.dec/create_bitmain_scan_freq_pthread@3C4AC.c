int create_bitmain_scan_freq_pthread()
{
  int v0; // r5
  thr_info *v1; // r0
  void *(*v2)(void *); // r2
  const char *v3; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  v1 = (thr_info *)calloc(1u, 0x40u);
  LOWORD(v2) = -13139;
  HIWORD(v2) = (unsigned int)&loc_3CB9C >> 16;
  auto_freq_id = v1;
  if ( thr_info_create(v1, 0, v2, 0) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v3) = -25000;
      HIWORD(v3) = (unsigned int)"PWM percent : %d" >> 16;
      snprintf(tmp42, 0x1000u, v3, "create_bitmain_scan_freq_pthread");
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
