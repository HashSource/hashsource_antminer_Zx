void __fastcall every_asic_set_isl_voltage(int which_chain)
{
  const char *v1; // r8
  uint8_t *v2; // r6
  int v4; // r4
  uint8_t v5; // t1
  int v6; // r7
  uint16_t v7; // r1
  int v8; // lr
  unsigned __int16 *v9; // [sp+18h] [bp-100Ch]
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  LOWORD(v1) = -29156;
  v2 = isl_dev_addr;
  v4 = 0;
  v9 = &isl_vol[which_chain - 1][2];
  do
  {
    v5 = *v2++;
    v6 = v9[1];
    v7 = v9[1];
    ++v9;
    v8 = ISL_set_voltage_dynamic(v5, v7);
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      HIWORD(v1) = (unsigned int)" %d\n" >> 16;
      snprintf(tmp42, 0x1000u, v1, which_chain, v4, *(v2 - 1), "every_asic_set_isl_voltage", v6, v8);
      applog(5, tmp42, 0);
    }
    ++v4;
    cgsleep_ms(200);
  }
  while ( v4 != 3 );
}
