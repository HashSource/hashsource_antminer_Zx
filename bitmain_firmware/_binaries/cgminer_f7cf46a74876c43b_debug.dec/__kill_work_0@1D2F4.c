// Alternative name is '__kill_work.part.37'
void _kill_work_0()
{
  int v0; // r4
  int v1; // r0
  thr_info *thread; // r0
  cgpu_info *cgpu; // r3
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( opt_debug )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      strcpy(tmp42, "Received kill message");
      applog(7, tmp42, 1);
      if ( !opt_debug )
        goto LABEL_8;
      if ( use_syslog )
      {
LABEL_7:
        strcpy(tmp42, "Killing off watchpool thread");
        applog(7, tmp42, 1);
        goto LABEL_8;
      }
    }
    if ( opt_log_output || opt_log_level > 6 )
      goto LABEL_7;
  }
LABEL_8:
  cg_completion_timeout(thr_info_cancel, &control_thr[watchpool_thr_id], 1000);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Killing off watchdog thread");
    applog(7, tmp42, 1);
  }
  cg_completion_timeout(thr_info_cancel, &control_thr[watchdog_thr_id], 1000);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Shutting down mining threads");
    applog(7, tmp42, 1);
  }
  if ( mining_threads > 0 )
  {
    v0 = 0;
    do
    {
      v1 = v0++;
      thread = get_thread(v1);
      if ( thread )
      {
        cgpu = thread->cgpu;
        if ( cgpu )
          cgpu->shutdown = 1;
      }
    }
    while ( v0 < mining_threads );
  }
  sleep(1u);
  cg_completion_timeout(kill_mining, 0, 3000);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Killing off API thread");
    applog(7, tmp42, 1);
  }
  cg_completion_timeout(thr_info_cancel, &control_thr[api_thr_id], 1000);
}
