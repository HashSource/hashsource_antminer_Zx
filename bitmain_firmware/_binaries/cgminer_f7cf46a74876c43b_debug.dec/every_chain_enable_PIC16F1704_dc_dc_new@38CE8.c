void every_chain_enable_PIC16F1704_dc_dc_new()
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v2; // t1
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "every_chain_enable_PIC16F1704_dc_dc_new");
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
      enable_PIC16F1704_dc_dc_new();
      cgsleep_ms(200);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
}
