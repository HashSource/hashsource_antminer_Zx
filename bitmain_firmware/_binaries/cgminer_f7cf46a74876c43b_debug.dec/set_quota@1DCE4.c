char *__fastcall set_quota(char *arg)
{
  char *v2; // r0
  char *v3; // r4
  size_t v4; // r0
  size_t v5; // r6
  size_t v6; // r0
  size_t v7; // r4
  int v9; // r6
  pool *v10; // r0
  char *v11; // r1
  pool *v12; // r4
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
  if ( (int)(v5 - (v6 + 1)) <= 0 )
    return "No parameter for URL found";
  v9 = strtol(arg, 0, 10);
  if ( v9 < 0 )
    return "Invalid negative parameter for quota set";
  v10 = add_url();
  v11 = &arg[v7];
  v12 = v10;
  setup_url(v10, v11);
  v12->quota = v9;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Setting pool %d to quota %d", v12->pool_no, v9);
    applog(7, tmp42, 0);
  }
  adjust_quota_gcd();
  return 0;
}
