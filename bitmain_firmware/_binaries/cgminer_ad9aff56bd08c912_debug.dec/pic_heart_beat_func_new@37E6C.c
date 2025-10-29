void *__fastcall __noreturn pic_heart_beat_func_new(void *arg)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r1
  uint8_t *chain_exist; // r5
  int v8; // r4
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v1) = -28548;
    HIWORD(v1) = (unsigned int)"k_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    v2 = *v1;
    v3 = v1[1];
    v4 = v1[2];
    v5 = v1[3];
    v1 += 4;
    *(_DWORD *)tmp42 = v2;
    *(_DWORD *)&tmp42[4] = v3;
    *(_DWORD *)&tmp42[8] = v4;
    *(_DWORD *)&tmp42[12] = v5;
    v6 = v1[1];
    *(_DWORD *)&tmp42[16] = *v1;
    *(_DWORD *)&tmp42[20] = v6;
    applog(5, tmp42, 0);
  }
  while ( 1 )
  {
    chain_exist = dev.chain_exist;
    v8 = 0;
    sleep(0xAu);
    do
    {
      if ( *chain_exist++ )
      {
        if ( send_heart )
        {
          pthread_mutex_lock(&iic_mutex);
          i2c_slave_addr = v8;
          heart_beat_PIC16F1704_new();
          cgsleep_ms(100);
          pthread_mutex_unlock(&iic_mutex);
        }
      }
      ++v8;
    }
    while ( v8 != 4 );
  }
}
