void __fastcall check_extranonce_option(pool *pool, char *url)
{
  char *v3; // r0
  char *v4; // r4
  const char *v5; // r1
  const char *v6; // r2
  char extra_op[16]; // [sp+0h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v3 = strchr(url, 35);
  if ( v3 )
  {
    if ( !pool->extranonce_subscribe )
    {
      v4 = v3;
      strcpy(extra_op, v3);
      LOWORD(v5) = 16300;
      *v4 = 0;
      HIWORD(v5) = (unsigned int)"ed to malloc ret in ser_string" >> 16;
      if ( !strcmp(extra_op, v5) )
      {
        pool->extranonce_subscribe = 1;
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v6) = 16308;
          HIWORD(v6) = (unsigned int)"lloc ret in ser_string" >> 16;
          snprintf(tmp42, 0x1000u, v6, pool->pool_no);
          applog(7, tmp42, 0);
        }
      }
    }
  }
}
