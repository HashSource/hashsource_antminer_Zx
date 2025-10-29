void check_sensor_ID()
{
  int *v0; // r3
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  uint8_t *chain_exist; // r11
  int i; // r4
  int v7; // t1
  const char *v8; // r9
  int v9; // r5
  char *v10; // r8
  int v11; // r12
  int v12; // t1
  char tmp42[4096]; // [sp+18h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v0) = -23472;
    HIWORD(v0) = (unsigned int)"n:%d local:%d remote:%d" >> 16;
    v1 = *v0;
    v2 = v0[1];
    v3 = v0[2];
    v4 = v0[3];
    *(_DWORD *)tmp42 = v1;
    *(_DWORD *)&tmp42[4] = v2;
    *(_DWORD *)&tmp42[8] = v3;
    *(_DWORD *)&tmp42[12] = v4;
    applog(7, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v7 = *chain_exist++;
    if ( v7 == 1 )
    {
      LOWORD(v8) = -23520;
      v9 = 0;
      v10 = &sensor_id[4 * i];
      do
      {
        read_i2c_reg(i, v9, 0x4Cu, 0xFEu);
        v12 = *v10++;
        v11 = v12;
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          HIWORD(v8) = (unsigned int)"n%d Sensor%d temp offset : %02d, " >> 16;
          snprintf(tmp42, 0x1000u, v8, "check_sensor_ID", i, v9, v11);
          applog(3, tmp42, 0);
        }
        ++v9;
      }
      while ( v9 != 3 );
    }
  }
}
