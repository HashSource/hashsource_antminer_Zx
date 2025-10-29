bool __fastcall stratum_send(pool *pool, char *s, ssize_t len)
{
  pthread_mutex_t *p_stratum_lock; // r6
  int *v7; // r0
  int *v8; // r0
  send_ret v9; // r4
  bool result; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( opt_protocol && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    p_stratum_lock = &pool->stratum_lock;
    snprintf(tmp42, 0x1000u, "SEND: %s", s);
    applog(7, tmp42, 0);
    if ( pthread_mutex_lock(&pool->stratum_lock) )
    {
LABEL_11:
      v8 = _errno_location();
      snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v8, "util.c", "stratum_send", 1893);
      applog(3, tmp42, 1);
      quit(1);
    }
  }
  else
  {
    p_stratum_lock = &pool->stratum_lock;
    if ( pthread_mutex_lock(&pool->stratum_lock) )
      goto LABEL_11;
  }
  if ( !pool->stratum_active )
  {
    if ( pthread_mutex_unlock(p_stratum_lock) )
      goto LABEL_6;
    selective_yield();
    goto LABEL_24;
  }
  v9 = _stratum_send(pool, s, len);
  if ( pthread_mutex_unlock(p_stratum_lock) )
  {
LABEL_6:
    v7 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v7, "util.c", "stratum_send", 1896);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  if ( v9 == send_ret::SEND_SENDFAIL )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42, "Failed to send in stratum_send");
      applog(7, tmp42, 0);
      suspend_stratum(pool);
      return 0;
    }
    goto LABEL_21;
  }
  if ( v9 != send_ret::SEND_INACTIVE )
  {
    if ( v9 != send_ret::SEND_SELECTFAIL )
      return v9 == send_ret::SEND_OK;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "Write select failed on pool %d sock", pool->pool_no);
      applog(7, tmp42, 0);
    }
LABEL_21:
    suspend_stratum(pool);
    return 0;
  }
LABEL_24:
  result = opt_debug;
  if ( opt_debug && (use_syslog || (result = opt_log_output) || opt_log_level > 6) )
  {
    strcpy(tmp42, "Stratum send failed due to no pool stratum_active");
    applog(7, tmp42, 0);
    return 0;
  }
  return result;
}
