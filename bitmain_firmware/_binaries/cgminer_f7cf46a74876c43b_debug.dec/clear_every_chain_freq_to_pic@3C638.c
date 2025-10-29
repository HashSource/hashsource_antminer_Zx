int clear_every_chain_freq_to_pic()
{
  uint8_t *chain_exist; // r5
  int v1; // r7
  int v2; // r4
  int v3; // t1
  unsigned __int8 freq_table[4][9]; // [sp+4h] [bp-24h] BYREF

  chain_exist = dev.chain_exist;
  v1 = 1;
  v2 = 0;
  memset(freq_table, 0, sizeof(freq_table));
  do
  {
    v3 = *chain_exist++;
    if ( v3 == 1 )
    {
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = v2;
      v1 = write_data_to_PIC16F1704_flash(freq_table[v2], 0, 9);
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
    ++v2;
  }
  while ( v2 != 4 );
  return v1;
}
