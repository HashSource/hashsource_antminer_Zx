int __fastcall create_bitmain_check_miner_status_pthread(bitmain_ZCASH_info *info)
{
  int v1; // r6
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  check_miner_status_id = (thr_info *)calloc(1u, 0x40u);
  if ( thr_info_create(check_miner_status_id, 0, (void *(*)(void *))check_miner_status, info) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_check_miner_status_pthread");
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
