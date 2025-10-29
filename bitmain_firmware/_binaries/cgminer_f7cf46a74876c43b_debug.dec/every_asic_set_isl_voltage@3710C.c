void __fastcall every_asic_set_isl_voltage(int which_chain)
{
  uint8_t *v1; // r6
  int v3; // r4
  uint8_t v4; // t1
  int v5; // r7
  uint16_t v6; // r1
  int v7; // lr
  unsigned __int16 *v8; // [sp+18h] [bp-100Ch]
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  v1 = isl_dev_addr;
  v3 = 0;
  v8 = &isl_vol[which_chain - 1][2];
  do
  {
    v4 = *v1++;
    v5 = v8[1];
    v6 = v8[1];
    ++v8;
    v7 = ISL_set_voltage_dynamic(v4, v6);
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "chain%d asic%d addr %02x, %s set vol %d, get vol %d",
        which_chain,
        v3,
        *(v1 - 1),
        "every_asic_set_isl_voltage",
        v5,
        v7);
      applog(5, tmp42, 0);
    }
    ++v3;
    cgsleep_ms(200);
  }
  while ( v3 != 3 );
}
