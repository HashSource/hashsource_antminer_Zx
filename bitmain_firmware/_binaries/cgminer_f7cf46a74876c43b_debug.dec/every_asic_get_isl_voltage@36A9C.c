void __fastcall every_asic_get_isl_voltage(int which_chain)
{
  uint8_t *v1; // r6
  unsigned __int16 *v3; // r5
  int i; // r4
  uint8_t v5; // t1
  _BOOL4 v6; // r7
  int v7; // r12
  unsigned __int16 vol; // [sp+16h] [bp-1006h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v1 = isl_dev_addr;
  v3 = &isl_vol[which_chain - 1][2];
  for ( i = 0; i != 3; ++i )
  {
    v5 = *v1++;
    vol = 0;
    ISL_get_voltage(v5, &vol);
    v6 = use_syslog;
    v7 = vol;
    v3[1] = vol;
    ++v3;
    if ( v6 || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "chain %d asic = %d vol=%u\n", which_chain, i, v7);
      applog(5, tmp42, 0);
    }
  }
}
