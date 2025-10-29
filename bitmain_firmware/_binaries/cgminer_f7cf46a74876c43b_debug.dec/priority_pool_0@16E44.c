// Alternative name is 'priority_pool.part.11'
pool *__fastcall priority_pool_0(int choice)
{
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x1000u, "WTF No pool %d found!", choice);
    applog(3, tmp42, 0);
  }
  return pools[choice];
}
