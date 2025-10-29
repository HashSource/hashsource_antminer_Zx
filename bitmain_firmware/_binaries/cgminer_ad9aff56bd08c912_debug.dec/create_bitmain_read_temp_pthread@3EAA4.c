int create_bitmain_read_temp_pthread()
{
  int v0; // r6
  thr_info *v1; // r0
  void *(*v2)(void *); // r2
  const char *v3; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v1 = (thr_info *)calloc(1u, 0x40u);
  LOWORD(v2) = -7291;
  HIWORD(v2) = (unsigned int)&loc_3E32C >> 16;
  read_temp_id = v1;
  if ( thr_info_create(v1, 0, v2, v1) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v3) = -23116;
      HIWORD(v3) = (unsigned int)"p_func" >> 16;
      snprintf(tmp42, 0x1000u, v3, "create_bitmain_read_temp_pthread");
      applog(7, tmp42, 0);
    }
    return -7;
  }
  else
  {
    pthread_detach(read_temp_id->pth);
    cgsleep_ms(500);
    return v0;
  }
}
