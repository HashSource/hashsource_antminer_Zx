bool __fastcall submit_nonce_1(thr_info *thr, work *work, uint32_t nonce, int *nofull)
{
  unsigned int v7; // r2
  _BOOL4 v8; // r4
  bool v9; // r3
  int *v10; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r6
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
      LOWORD(v10) = 1764;
      HIWORD(v10) = (unsigned int)" share: %s" >> 16;
      v11 = *v10;
      v12 = v10[1];
      v13 = v10[2];
      v14 = v10[3];
      v15 = v10[4];
      *(_DWORD *)tmp42 = v11;
      *(_DWORD *)&tmp42[4] = v12;
      *(_DWORD *)&tmp42[8] = v13;
      *(_DWORD *)&tmp42[12] = v14;
      *(_WORD *)&tmp42[16] = v15;
      tmp42[18] = BYTE2(v15);
      applog(7, tmp42, 0);
      return v8;
    }
    return v9;
  }
}
