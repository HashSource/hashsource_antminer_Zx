void every_chain_set_isl_voltage()
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v2; // t1

  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      every_asic_set_isl_voltage(i);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
}
