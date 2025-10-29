// Alternative name is 'stratum_resumed.part.47'
void __fastcall stratum_resumed_0(pool *pool)
{
  const char *v2; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v2) = 1224;
    HIWORD(v2) = (unsigned int)", testing stability" >> 16;
    snprintf(tmp42, 0x1000u, v2, pool->pool_no);
    applog(7, tmp42, 0);
  }
  pool_resus(pool);
}
