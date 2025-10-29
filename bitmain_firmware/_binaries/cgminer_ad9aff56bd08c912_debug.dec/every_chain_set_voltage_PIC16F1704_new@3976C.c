void __fastcall every_chain_set_voltage_PIC16F1704_new(unsigned __int16 voltage)
{
  int v1; // r3
  double v2; // d7
  const char *v3; // r2
  uint8_t *chain_exist; // r5
  int i; // r4
  int v6; // t1
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  v1 = use_syslog;
  v2 = 1609.92742 - (double)voltage * 182.739369 / 100.0;
  if ( use_syslog || (v1 = opt_log_output) != 0 || (v1 = opt_log_level, opt_log_level > 4) )
  {
    LOWORD(v3) = -26852;
    HIWORD(v3) = (unsigned int)" %s ok, freq = %d\n\n" >> 16;
    snprintf(tmp42, 0x1000u, v3, v1, v2, voltage);
    applog(5, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v6 = *chain_exist++;
    if ( v6 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      set_PIC16F1704_voltage_new((unsigned int)v2);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
  cgsleep_ms(500);
}
