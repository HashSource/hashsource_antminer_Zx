void __fastcall pool_died(pool *pool)
{
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( !pool_tset((int)pool, &pool->idle) )
  {
    cgtime(&pool->tv_idle);
    if ( pool == current_pool() )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "Pool %d %s not responding!", pool->pool_no, pool->rpc_url);
        applog(4, tmp42, 0);
      }
      switch_pools(0);
    }
    else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "Pool %d %s failed to return work", pool->pool_no, pool->rpc_url);
      applog(7, tmp42, 0);
    }
  }
}
