void every_chain_get_PIC16F1704_freq_new()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r4
  uint8_t *chain_exist; // r5
  const char *v11; // r8
  int i; // r4
  int v13; // t1
  int v14; // [sp+4h] [bp-1010h]
  unsigned __int16 freq_read_back[4]; // [sp+8h] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1004h] BYREF

  memset(freq_read_back, 0, sizeof(freq_read_back));
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -26752;
    HIWORD(v0) = (unsigned int)"k_data[2] = 0x%02x\n\n" >> 16;
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
    v9 = v0[4];
    *(_DWORD *)&tmp42[16] = v5;
    *(_DWORD *)&tmp42[20] = v6;
    *(_DWORD *)&tmp42[24] = v7;
    *(_DWORD *)&tmp42[28] = v8;
    *(_DWORD *)&tmp42[32] = v9;
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  LOWORD(v11) = -26780;
  for ( i = 0; i != 4; ++i )
  {
    v13 = *chain_exist++;
    if ( v13 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      get_PIC16F1704_freq_new(&freq_read_back[i]);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        HIWORD(v11) = (unsigned int)"k_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n" >> 16;
        snprintf(
          tmp42,
          0x1000u,
          v11,
          i,
          freq_read_back[i],
          v14,
          *(_DWORD *)freq_read_back,
          *(_DWORD *)&freq_read_back[2]);
        applog(5, tmp42, 0);
      }
    }
  }
  cgsleep_ms(500);
}
