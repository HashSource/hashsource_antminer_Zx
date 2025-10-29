void every_chain_disable_PIC16F1704_dc_dc_new()
{
  int *v0; // r5
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r1
  int v10; // r2
  uint8_t *chain_exist; // r5
  int i; // r4
  int v13; // t1
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -27496;
    HIWORD(v0) = (unsigned int)"set flash pointer error!\n\n" >> 16;
    v1 = *v0;
    v2 = v0[1];
    v3 = v0[2];
    v4 = v0[3];
    v0 += 4;
    *(_DWORD *)tmp42 = v1;
    *(_DWORD *)&tmp42[4] = v2;
    *(_DWORD *)&tmp42[8] = v3;
    *(_DWORD *)&tmp42[12] = v4;
    v5 = *v0;
    v6 = v0[1];
    v7 = v0[2];
    v8 = v0[3];
    v0 += 4;
    *(_DWORD *)&tmp42[16] = v5;
    *(_DWORD *)&tmp42[20] = v6;
    *(_DWORD *)&tmp42[24] = v7;
    *(_DWORD *)&tmp42[28] = v8;
    v9 = v0[1];
    v10 = v0[2];
    *(_DWORD *)&tmp42[32] = *v0;
    *(_DWORD *)&tmp42[36] = v9;
    tmp42[40] = v10;
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v13 = *chain_exist++;
    if ( v13 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      disable_PIC16F1704_dc_dc_new();
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
  cgsleep_ms(500);
}
