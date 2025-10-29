void every_chain_get_pic_version()
{
  uint8_t *chain_exist; // r5
  int v1; // r4
  int v2; // t1
  int PIC16F1704_software_version_new; // r9
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
          snprintf(tmp42, 0x1000u, "chain%d pic version %02x\n", v1, version[v1]);
          applog(5, tmp42, 0);
        }
      }
      else if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "chain%d pic version read failed\n", v1);
        applog(5, tmp42, 0);
      }
    }
    ++v1;
  }
  while ( v1 != 4 );
}
