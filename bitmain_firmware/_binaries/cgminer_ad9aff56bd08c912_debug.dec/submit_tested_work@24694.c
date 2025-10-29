bool __fastcall submit_tested_work(thr_info *thr, work *work)
{
  _BOOL4 v4; // r0
  work *v5; // r1
  bool v6; // r4
  work *v8; // r6

  update_work_stats(thr, work);
  v4 = fulltest(work->hash, work->target);
  if ( v4 )
  {
    v6 = v4;
    v8 = make_work();
    copy_work(v8, work, 0);
    submit_work_async(v8);
  }
  else
  {
    v6 = opt_debug;
    if ( opt_debug )
    {
      if ( use_syslog )
        return submit_tested_work_0(thr, v5);
      v6 = opt_log_output;
      if ( opt_log_output || opt_log_level > 6 )
        return submit_tested_work_0(thr, v5);
    }
  }
  return v6;
}
