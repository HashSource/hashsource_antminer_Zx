void *__fastcall __noreturn quit_thread(void *userdata)
{
  int *v1; // r0
  int *v2; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( !pthread_mutex_lock(&quit_restart_lock) )
  {
    if ( !pthread_mutex_unlock(&quit_restart_lock) )
    {
      selective_yield();
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        strcpy(tmp42, "API: killing cgminer");
        applog(7, tmp42, 0);
      }
      kill_work();
    }
    v2 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v2,
      "api.c",
      &_func___12372.__size[8],
      4938);
    applog(3, tmp42, 1);
    quit(1);
  }
  v1 = _errno_location();
  snprintf(
    tmp42,
    0x1000u,
    "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
    *v1,
    "api.c",
    &_func___12372.__size[8],
    4937);
  applog(3, tmp42, 1);
  quit(1);
}
