char *__fastcall set_quota(char *arg)
{
  char *v2; // r0
  char *v3; // r4
  size_t v4; // r0
  size_t v5; // r6
  size_t v6; // r0
  size_t v7; // r4
  char *result; // r0
  int v9; // r6
  pool *v10; // r0
  char *v11; // r1
  pool *v12; // r4
  const char *v13; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v2 = strchr(arg, 59);
  if ( !v2 )
    return "No semicolon separated quota;URL pair found";
  v3 = v2;
  v4 = strlen(arg);
  *v3 = 0;
  v5 = v4;
  v6 = strlen(arg);
  if ( !v6 )
    return "No parameter for quota found";
  v7 = v6 + 1;
  if ( (int)(v5 - (v6 + 1)) > 0 )
  {
    v9 = strtol(arg, 0, 10);
    if ( v9 >= 0 )
    {
      v10 = add_url();
      v11 = &arg[v7];
      v12 = v10;
      setup_url(v10, v11);
      v12->quota = v9;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v13) = 1624;
        HIWORD(v13) = (unsigned int)"lid negative parameter for quota set" >> 16;
        snprintf(tmp42, 0x1000u, v13, v12->pool_no, v9);
        applog(7, tmp42, 0);
      }
      adjust_quota_gcd();
      return 0;
    }
    else
    {
      LOWORD(result) = 1580;
      HIWORD(result) = (unsigned int)"ta found" >> 16;
    }
  }
  else
  {
    LOWORD(result) = 1552;
    HIWORD(result) = (unsigned int)"r found" >> 16;
  }
  return result;
}
