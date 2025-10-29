// Alternative name is 'new_nonce.isra.12'
int __fastcall new_nonce(thr_info *thr, __time_t nonce)
{
  int result; // r0
  char tmp42[4096]; // [sp+8h] [bp-1008h] BYREF

  if ( thr[3].last.tv_sec == nonce )
  {
    result = opt_debug;
    if ( opt_debug && (use_syslog || (result = opt_log_output) != 0 || opt_log_level > 6) )
    {
      snprintf(
        tmp42,
        0x1000u,
        "%s %d duplicate share detected as HW error",
        *(const char **)(thr->device_thread + 8),
        *(_DWORD *)&thr->primary_thread);
      applog(7, tmp42, 0);
      return 0;
    }
  }
  else
  {
    thr[3].last.tv_sec = nonce;
    return 1;
  }
  return result;
}
