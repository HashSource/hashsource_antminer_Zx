bool __fastcall submit_nonce_1(thr_info *thr, work *work, uint32_t nonce, int *nofull)
{
  unsigned int v7; // r2
  _BOOL4 v8; // r4
  bool v9; // r3
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( nofull )
    *nofull = 0;
  *(_DWORD *)&work->data[76] = nonce;
  rebuild_hash(work);
  v7 = 0xFFFF;
  if ( !opt_scrypt )
    v7 = 0;
  if ( *(_DWORD *)&work->hash[28] > v7 )
  {
    inc_hw_errors(thr);
    return 0;
  }
  else
  {
    update_work_stats(thr, work);
    v8 = fulltest(work->hash, work->target);
    if ( v8 )
      return v8;
    if ( nofull )
      *nofull = 1;
    v9 = opt_debug;
    if ( opt_debug && (use_syslog || (v9 = opt_log_output) || opt_log_level > 6) )
    {
      strcpy(tmp42, "Share above target");
      applog(7, tmp42, 0);
      return v8;
    }
    return v9;
  }
}
