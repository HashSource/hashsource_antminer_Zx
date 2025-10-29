void __fastcall suspend_stratum(pool *pool)
{
  const char *v2; // r2
  int *v3; // r0
  int v4; // r1
  const char *v5; // r2
  int *v6; // r0
  int v7; // r1
  const char *v8; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v2) = 16436;
    HIWORD(v2) = (unsigned int)"Pool %d extranonce subscribing enabled." >> 16;
    snprintf(tmp42, 0x1000u, v2, pool->pool_no);
    applog(7, tmp42, 0);
  }
  if ( pthread_mutex_lock(&pool->stratum_lock) )
  {
    v3 = _errno_location();
    LOWORD(v4) = 15984;
    LOWORD(v5) = -968;
    HIWORD(v4) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v5) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v5, *v3, v4, "suspend_stratum", 3354);
    applog(3, tmp42, 1);
    quit(1);
  }
  _suspend_stratum(pool);
  if ( pthread_mutex_unlock(&pool->stratum_lock) )
  {
    v6 = _errno_location();
    LOWORD(v7) = 15984;
    LOWORD(v8) = -920;
    HIWORD(v7) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v8) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v8, *v6, v7, "suspend_stratum", 3356);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
}
