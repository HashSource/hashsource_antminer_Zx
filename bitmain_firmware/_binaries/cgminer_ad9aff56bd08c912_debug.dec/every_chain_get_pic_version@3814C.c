void every_chain_get_pic_version()
{
  uint8_t *chain_exist; // r5
  int v1; // r4
  int v2; // t1
  int PIC16F1704_software_version_new; // r9
  const char *v4; // r2
  const char *v5; // r2
  unsigned __int8 version[4]; // [sp+Ch] [bp-1008h] BYREF
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  chain_exist = dev.chain_exist;
  v1 = 0;
  *(_DWORD *)version = 0;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = v1;
      PIC16F1704_software_version_new = get_PIC16F1704_software_version_new(&version[v1]);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
      if ( PIC16F1704_software_version_new == 1 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          LOWORD(v5) = -28388;
          HIWORD(v5) = (unsigned int)"k_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x" >> 16;
          snprintf(tmp42, 0x1000u, v5, v1, version[v1]);
          applog(5, tmp42, 0);
        }
      }
      else if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        LOWORD(v4) = -28360;
        HIWORD(v4) = (unsigned int)"data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x" >> 16;
        snprintf(tmp42, 0x1000u, v4, v1);
        applog(5, tmp42, 0);
      }
    }
    ++v1;
  }
  while ( v1 != 4 );
}
