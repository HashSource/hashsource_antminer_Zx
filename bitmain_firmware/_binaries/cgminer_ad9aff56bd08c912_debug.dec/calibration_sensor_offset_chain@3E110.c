void __fastcall calibration_sensor_offset_chain(unsigned __int8 which_chain)
{
  int v1; // r6
  const char *v2; // r10
  char *v3; // r5
  char *v4; // r8
  int v5; // r4
  int v6; // r3
  int v7; // r12
  char v8; // r2
  int v9; // r3
  unsigned __int8 v10[4]; // [sp+Ch] [bp-1008h]
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v1 = which_chain;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%d %s", which_chain, "calibration_sensor_offset_chain");
    applog(5, tmp42, 0);
  }
  LOWORD(v2) = -23548;
  v3 = (char *)&dev + 24 * (__int16)v1;
  v4 = &gTempOffsetValue[4 * (__int16)v1];
  *(_DWORD *)v10 = 0;
  do
  {
    LOBYTE(v5) = 11;
    do
    {
      read_i2c_reg(v1, v10[0], 0x4Cu, 1u);
      read_i2c_reg(v1, v10[0], 0x4Cu, 0);
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        HIWORD(v2) = (unsigned int)" read back is %02d\n" >> 16;
        snprintf(tmp42, 0x1000u, v2, v1, *((__int16 *)v3 + 64), *((__int16 *)v3 + 65));
        applog(5, tmp42, 0);
      }
      v6 = *((__int16 *)v3 + 64);
      v7 = *((__int16 *)v3 + 65);
      v8 = *v4 + v6;
      v9 = v6 - v7;
      *v4 = v8 - v7;
      if ( v9 < 0 )
        v9 = -v9;
      if ( v9 <= 2 )
        break;
      set_temperature_offset_value_chain_sensor(v1, v10[0]);
      v5 = (unsigned __int8)(v5 - 1);
    }
    while ( v5 );
    ++v4;
    v3 += 8;
    ++*(_DWORD *)v10;
  }
  while ( *(_DWORD *)v10 != 3 );
}
