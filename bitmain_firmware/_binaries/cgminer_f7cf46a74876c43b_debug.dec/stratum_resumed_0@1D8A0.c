// Alternative name is 'stratum_resumed.part.47'
void __fastcall stratum_resumed_0(pool *pool)
{
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Stratum connection to pool %d resumed", pool->pool_no);
    applog(7, tmp42, 0);
  }
  pool_resus(pool);
}
