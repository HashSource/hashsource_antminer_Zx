bool __fastcall submit_noffset_nonce(thr_info *thr, work *work_in, uint32_t nonce, int noffset)
{
  work *work; // r4
  unsigned int v9; // r3
  _BOOL4 v10; // r5
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  work = make_work();
  copy_work(work, work_in, noffset);
  *(_DWORD *)&work->data[76] = nonce;
  rebuild_hash(work);
  v9 = 0xFFFF;
  if ( !opt_scrypt )
    v9 = 0;
  if ( *(_DWORD *)&work->hash[28] > v9 )
  {
    clean_work(work);
    free(work);
    inc_hw_errors(thr);
    return 0;
  }
  else
  {
    update_work_stats(thr, work);
    if ( opt_benchfile && opt_benchfile_display )
      benchfile_dspwork(work, nonce);
    v10 = fulltest(work->hash, work->target);
    if ( v10 )
    {
      submit_work_async(work);
      return v10;
    }
    clean_work(work);
    free(work);
    LOBYTE(v10) = opt_debug;
    if ( opt_debug )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
        return v10;
      snprintf(tmp42, 0x1000u, "%s %d: Share above target", thr->cgpu->drv->name, thr->cgpu->device_id);
      applog(7, tmp42, 0);
      return v10;
    }
    else
    {
      return 1;
    }
  }
}
