void __fastcall check_extranonce_option(pool *pool, char *url)
{
  char *v3; // r0
  char *v4; // r4
  char extra_op[16]; // [sp+0h] [bp-1010h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v3 = strchr(url, 35);
  if ( v3 )
  {
    if ( !pool->extranonce_subscribe )
    {
      v4 = v3;
      strcpy(extra_op, v3);
      *v4 = 0;
      if ( !strcmp(extra_op, "#xnsub") )
      {
        pool->extranonce_subscribe = 1;
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, "Pool %d extranonce subscribing enabled.", pool->pool_no);
          applog(7, tmp42, 0);
        }
      }
    }
  }
}
