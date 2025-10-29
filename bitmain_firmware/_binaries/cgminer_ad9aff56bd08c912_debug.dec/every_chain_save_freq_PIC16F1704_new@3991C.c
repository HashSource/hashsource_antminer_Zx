void __fastcall every_chain_save_freq_PIC16F1704_new(unsigned __int16 freq)
{
  const char *v2; // r3
  uint8_t *chain_exist; // r5
  int i; // r4
  int v5; // t1
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -26800;
    HIWORD(v2) = (unsigned int)"] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n" >> 16;
    snprintf(tmp42, 0x1000u, "%s %u", v2, freq);
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v5 = *chain_exist++;
    if ( v5 == 1 )
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
