int __fastcall every_chain_write_freq_to_pic(unsigned __int8 (*freq_table)[9])
{
  uint8_t *chain_exist; // r5
  int v3; // r9
  int i; // r4
  int v5; // t1

  chain_exist = dev.chain_exist;
  v3 = 1;
  for ( i = 0; i != 4; ++i )
  {
    v5 = *chain_exist++;
    if ( v5 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      v3 = write_data_to_PIC16F1704_flash(&(*freq_table)[9 * i], 0, 9);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
  return v3;
}
