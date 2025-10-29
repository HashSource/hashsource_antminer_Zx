void __fastcall every_chain_save_freq_PIC16F1704_new(unsigned __int16 freq)
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v4; // t1
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s %u", "set freq:", freq);
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v4 = *chain_exist++;
    if ( v4 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      save_freq_PIC16F1704_new(freq);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
  cgsleep_ms(500);
}
