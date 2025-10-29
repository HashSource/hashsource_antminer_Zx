bool __fastcall submit_nonce(thr_info *thr, work *work, uint32_t nonce)
{
  int v6; // r0
  bool v7; // r4
  unsigned int v8; // r3

  v6 = new_nonce((thr_info *)thr->cgpu, nonce);
  if ( !v6 )
    goto LABEL_5;
  v7 = v6;
  *(_DWORD *)&work->data[76] = nonce;
  rebuild_hash(work);
  v8 = 0xFFFF;
  if ( !opt_scrypt )
    v8 = 0;
  if ( *(_DWORD *)&work->hash[28] <= v8 )
  {
    submit_tested_work(thr, work);
    if ( opt_benchfile && opt_benchfile_display )
    {
      v7 = opt_benchfile_display;
      benchfile_dspwork(work, nonce);
    }
  }
  else
  {
LABEL_5:
    v7 = 0;
    inc_hw_errors(thr);
  }
  return v7;
}
