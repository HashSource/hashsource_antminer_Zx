int create_bitmain_read_temp_pthread()
{
  int v0; // r6
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  read_temp_id = (thr_info *)calloc(1u, 0x40u);
  if ( thr_info_create(read_temp_id, 0, (void *(*)(void *))read_temp_func, read_temp_id) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "%s: create thread for read temp", "create_bitmain_read_temp_pthread");
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
