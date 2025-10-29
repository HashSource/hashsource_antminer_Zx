void every_chain_get_PIC16F1704_freq_new()
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v2; // t1
  int v3; // [sp+4h] [bp-1010h]
  unsigned __int16 freq_read_back[4]; // [sp+8h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  memset(freq_read_back, 0, sizeof(freq_read_back));
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "every_chain_get_PIC16F1704_freq_new");
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      get_PIC16F1704_freq_new(&freq_read_back[i]);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(
          tmp42,
          0x1000u,
          "chain%d pic freq = 0x%08x\n",
          i,
          freq_read_back[i],
          v3,
          *(_DWORD *)freq_read_back,
          *(_DWORD *)&freq_read_back[2]);
        applog(5, tmp42, 0);
      }
    }
  }
  cgsleep_ms(500);
}
