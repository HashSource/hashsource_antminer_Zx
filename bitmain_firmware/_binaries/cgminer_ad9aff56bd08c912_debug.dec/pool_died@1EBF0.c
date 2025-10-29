void __fastcall pool_died(pool *pool)
{
  const char *v2; // r2
  const char *v3; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( !pool_tset((int)pool, &pool->idle) )
  {
    cgtime(&pool->tv_idle);
    if ( pool == current_pool() )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        LOWORD(v3) = 1868;
        HIWORD(v3) = (unsigned int)"ect on pool %d" >> 16;
        snprintf(tmp42, 0x1000u, v3, pool->pool_no, pool->rpc_url);
        applog(4, tmp42, 0);
      }
      switch_pools(0);
    }
    else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v2) = 1896;
      HIWORD(v2) = (unsigned int)" pool %d %s" >> 16;
      snprintf(tmp42, 0x1000u, v2, pool->pool_no, pool->rpc_url);
      applog(7, tmp42, 0);
    }
  }
}
