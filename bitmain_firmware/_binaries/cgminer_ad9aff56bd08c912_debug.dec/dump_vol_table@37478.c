void dump_vol_table()
{
  unsigned __int16 *v0; // r6
  const char *v1; // r8
  int i; // r5
  int j; // r4
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v0 = isl_vol[0];
  LOWORD(v1) = -29080;
  for ( i = 0; i != 4; ++i )
  {
    for ( j = 0; j != 3; ++j )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        HIWORD(v1) = (unsigned int)"vol %d, set again!\n" >> 16;
        snprintf(tmp42, 0x1000u, v1, i, j, v0[j]);
        applog(5, tmp42, 0);
      }
    }
    v0 += 3;
  }
}
