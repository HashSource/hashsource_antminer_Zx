void __fastcall every_chain_get_voltage_PIC16F1704_new(unsigned __int16 voltage)
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v3; // t1
  uint8_t pic_voltage1; // [sp+Fh] [bp-1001h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v3 = *chain_exist++;
    if ( v3 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      get_PIC16F1704_voltage_new(&pic_voltage1);
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "Chain %u voltage %u", i, pic_voltage1);
        applog(5, tmp42, 0);
      }
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
  cgsleep_ms(500);
}
