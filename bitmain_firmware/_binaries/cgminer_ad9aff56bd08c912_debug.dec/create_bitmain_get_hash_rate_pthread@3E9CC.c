int create_bitmain_get_hash_rate_pthread()
{
  int v0; // r6
  thr_info *v1; // r0
  void *(*v2)(void *); // r2
  const char *v3; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v1 = (thr_info *)calloc(1u, 0x40u);
  LOWORD(v2) = 16289;
  HIWORD(v2) = ((unsigned int)&loc_33E8E + 3) >> 16;
  read_hash_rate = v1;
  if ( thr_info_create(v1, 0, v2, v1) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v3) = -23168;
      HIWORD(v3) = (unsigned int)"temperature, close PIC and need reboot!!!" >> 16;
      snprintf(tmp42, 0x1000u, v3, "create_bitmain_get_hash_rate_pthread");
      applog(7, tmp42, 0);
    }
    return -6;
  }
  else
  {
    pthread_detach(read_hash_rate->pth);
    cgsleep_ms(500);
    return v0;
  }
}
