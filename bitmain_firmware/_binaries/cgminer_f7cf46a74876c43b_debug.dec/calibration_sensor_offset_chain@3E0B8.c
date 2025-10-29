void __fastcall calibration_sensor_offset_chain(unsigned __int8 which_chain)
{
  int v1; // r6
  char *v2; // r5
  char *v3; // r8
  int v4; // r4
  int v5; // r3
  int v6; // r12
  char v7; // r2
  int v8; // r3
  unsigned __int8 v9[4]; // [sp+Ch] [bp-1008h]
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v1 = which_chain;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%d %s", which_chain, "calibration_sensor_offset_chain");
    applog(5, tmp42, 0);
  }
  v2 = (char *)&dev + 24 * (__int16)v1;
  v3 = &gTempOffsetValue[4 * (__int16)v1];
  *(_DWORD *)v9 = 0;
  do
  {
    LOBYTE(v4) = 11;
    do
    {
      read_i2c_reg(v1, v9[0], 0x4Cu, 1u);
      read_i2c_reg(v1, v9[0], 0x4Cu, 0);
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "chain:%d local:%d remote:%d", v1, *((__int16 *)v2 + 64), *((__int16 *)v2 + 65));
        applog(5, tmp42, 0);
      }
      v5 = *((__int16 *)v2 + 64);
      v6 = *((__int16 *)v2 + 65);
      v7 = *v3 + v5;
      v8 = v5 - v6;
      *v3 = v7 - v6;
      if ( v8 < 0 )
        v8 = -v8;
      if ( v8 <= 2 )
        break;
      set_temperature_offset_value_chain_sensor(v1, v9[0]);
      v4 = (unsigned __int8)(v4 - 1);
    }
    while ( v4 );
    ++v3;
    v2 += 8;
    ++*(_DWORD *)v9;
  }
  while ( *(_DWORD *)v9 != 3 );
}
