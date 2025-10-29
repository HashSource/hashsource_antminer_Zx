void app_restart()
{
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42, 0x1000u, "Attempting to restart %s", packagename);
    applog(4, tmp42, 0);
  }
  cg_completion_timeout(_kill_work, 0, 5000);
  cgtime(&total_tv_end);
  if ( forkpid > 0 )
  {
    kill(forkpid, 15);
    forkpid = 0;
  }
  execv(*initial_args, initial_args);
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    strcpy(tmp42, "Failed to restart application");
    applog(4, tmp42, 0);
  }
}
