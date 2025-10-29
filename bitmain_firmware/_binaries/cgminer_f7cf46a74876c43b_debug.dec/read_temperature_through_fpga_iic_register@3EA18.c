unsigned __int8 __fastcall read_temperature_through_fpga_iic_register(unsigned __int8 which_chain)
{
  unsigned int v1; // r4
  unsigned __int8 v2; // r6

  v1 = (which_chain << 16) | 0x1900000;
  pthread_mutex_lock(&i2c_mutex);
  v2 = i2c_read(v1);
  i2c_read(v1);
  cgsleep_ms(100);
  pthread_mutex_unlock(&i2c_mutex);
  return v2;
}
