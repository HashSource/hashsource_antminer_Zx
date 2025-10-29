void __fastcall pool_resus(pool *pool)
{
  pool_strategy v1; // r3
  int prio; // r5
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = pool_strategy_0;
  pool->seq_getfails = 0;
  if ( v1 || (prio = pool->prio, prio >= cp_prio()) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "Pool %d %s alive", pool->pool_no, pool->rpc_url);
      applog(7, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42, 0x1000u, "Pool %d %s alive, testing stability", pool->pool_no, pool->rpc_url);
    applog(4, tmp42, 0);
  }
}
