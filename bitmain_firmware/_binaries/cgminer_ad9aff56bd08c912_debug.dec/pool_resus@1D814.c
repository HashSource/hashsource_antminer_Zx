void __fastcall pool_resus(pool *pool)
{
  pool_strategy v1; // r3
  const char *v3; // r2
  int prio; // r5
  const char *v5; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = pool_strategy_0;
  pool->seq_getfails = 0;
  if ( v1 || (prio = pool->prio, prio >= cp_prio()) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v3) = 1204;
      HIWORD(v3) = (unsigned int)"ds" >> 16;
      snprintf(tmp42, 0x1000u, v3, pool->pool_no, pool->rpc_url);
      applog(7, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v5) = 1168;
    HIWORD(v5) = (unsigned int)"API thread" >> 16;
    snprintf(tmp42, 0x1000u, v5, pool->pool_no, pool->rpc_url);
    applog(4, tmp42, 0);
  }
}
