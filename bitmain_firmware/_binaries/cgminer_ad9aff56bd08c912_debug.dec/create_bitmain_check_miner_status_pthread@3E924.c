int __fastcall create_bitmain_check_miner_status_pthread(bitmain_ZCASH_info *info)
{
  int v1; // r6
  thr_info *v3; // r0
  void *(*v4)(void *); // r2
  const char *v5; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v3 = (thr_info *)calloc(1u, 0x40u);
  LOWORD(v4) = -20355;
  HIWORD(v4) = (unsigned int)&loc_3AF6C >> 16;
  check_miner_status_id = v3;
  if ( thr_info_create(v3, 0, v4, info) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v5) = -25000;
      HIWORD(v5) = (unsigned int)"PWM percent : %d" >> 16;
      snprintf(tmp42, 0x1000u, v5, "create_bitmain_check_miner_status_pthread");
      applog(7, tmp42, 0);
    }
    return -5;
  }
  else
  {
    pthread_detach(check_miner_status_id->pth);
    cgsleep_ms(500);
    return v1;
  }
}
