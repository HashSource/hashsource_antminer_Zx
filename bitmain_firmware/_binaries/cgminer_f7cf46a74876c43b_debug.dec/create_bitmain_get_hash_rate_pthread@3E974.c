int create_bitmain_get_hash_rate_pthread()
{
  int v0; // r6
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  read_hash_rate = (thr_info *)calloc(1u, 0x40u);
  if ( thr_info_create(read_hash_rate, 0, (void *(*)(void *))get_hash_rate, read_hash_rate) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(
        tmp42,
        0x1000u,
        "%s: create thread for get hashrate from asic failed",
        "create_bitmain_get_hash_rate_pthread");
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
