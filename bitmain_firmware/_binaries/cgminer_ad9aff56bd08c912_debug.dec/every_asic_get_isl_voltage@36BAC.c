void __fastcall every_asic_get_isl_voltage(int which_chain)
{
  const char *v1; // r8
  uint8_t *v2; // r6
  unsigned __int16 *v4; // r5
  int i; // r4
  uint8_t v6; // t1
  _BOOL4 v7; // r7
  int v8; // r12
  unsigned __int16 vol; // [sp+16h] [bp-1006h] BYREF
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  LOWORD(v1) = -29492;
  v2 = isl_dev_addr;
  v4 = &isl_vol[which_chain - 1][2];
  for ( i = 0; i != 3; ++i )
  {
    v6 = *v2++;
    vol = 0;
    ISL_get_voltage(v6, &vol);
    v7 = use_syslog;
    v8 = vol;
    v4[1] = vol;
    ++v4;
    if ( v7 || opt_log_output || opt_log_level > 4 )
    {
      HIWORD(v1) = (unsigned int)"read_back_data[1] = 0x%02x" >> 16;
      snprintf(tmp42, 0x1000u, v1, which_chain, i, v8);
      applog(5, tmp42, 0);
    }
  }
}
