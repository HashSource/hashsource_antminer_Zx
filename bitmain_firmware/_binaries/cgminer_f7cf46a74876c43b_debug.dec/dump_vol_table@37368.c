void dump_vol_table()
{
  unsigned __int16 *v0; // r6
  int i; // r5
  int j; // r4
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v0 = isl_vol[0];
  for ( i = 0; i != 4; ++i )
  {
    for ( j = 0; j != 3; ++j )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "chain %d asic %d vol %d\n", i, j, v0[j]);
        applog(5, tmp42, 0);
      }
    }
    v0 += 3;
  }
}
