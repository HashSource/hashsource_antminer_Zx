unsigned __int8 __cdecl i2c_read(unsigned int config_data)
{
  unsigned int ret_data; // [sp+408h] [bp+408h]
  unsigned int send_counter; // [sp+40Ch] [bp+40Ch]

  send_counter = 0;
  ret_data = 255;
  i2c_write(config_data | 0x2000000);
  do
  {
    usleep(0x1388u);
    ret_data = read_axi_fpga(0xCu);
  }
  while ( (ret_data & 0x80000000) == 0 );
  return ret_data;
}
