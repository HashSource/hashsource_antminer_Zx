void *__fastcall restart_thread_0(void *userdata)
{
  int *v2; // r0
  int *v3; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&quit_restart_lock) )
  {
    v2 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v2,
      "api.c",
      &_func___12372.__size[20],
      4951);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&quit_restart_lock) )
  {
    v3 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v3,
      "api.c",
      &_func___12372.__size[20],
      4952);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "API: restarting cgminer");
    applog(7, tmp42, 0);
  }
  app_restart();
  return 0;
}
