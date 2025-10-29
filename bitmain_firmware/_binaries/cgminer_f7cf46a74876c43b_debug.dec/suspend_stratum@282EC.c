void __fastcall suspend_stratum(pool *pool)
{
  int *v2; // r0
  int *v3; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Closing socket for stratum pool %d", pool->pool_no);
    applog(7, tmp42, 0);
  }
  if ( pthread_mutex_lock(&pool->stratum_lock) )
  {
    v2 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v2, "util.c", "suspend_stratum", 3354);
    applog(3, tmp42, 1);
    quit(1);
  }
  _suspend_stratum(pool);
  if ( pthread_mutex_unlock(&pool->stratum_lock) )
  {
    v3 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v3,
      "util.c",
      "suspend_stratum",
      3356);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
}
