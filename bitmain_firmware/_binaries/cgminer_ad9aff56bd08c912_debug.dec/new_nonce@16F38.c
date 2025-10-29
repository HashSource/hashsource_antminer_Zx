// Alternative name is 'new_nonce.isra.12'
int __fastcall new_nonce(thr_info *thr, __time_t nonce)
{
  int result; // r0
  const char *v4; // r2
  char tmp42[4096]; // [sp+8h] [bp-1008h] BYREF

  if ( thr[3].last.tv_sec == nonce )
  {
    result = opt_debug;
    if ( opt_debug && (use_syslog || (result = opt_log_output) != 0 || opt_log_level > 6) )
    {
      LOWORD(v4) = -3052;
      HIWORD(v4) = (unsigned int)"ng support.\n" >> 16;
      snprintf(tmp42, 0x1000u, v4, *(_DWORD *)(thr->device_thread + 8), *(_DWORD *)&thr->primary_thread);
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
