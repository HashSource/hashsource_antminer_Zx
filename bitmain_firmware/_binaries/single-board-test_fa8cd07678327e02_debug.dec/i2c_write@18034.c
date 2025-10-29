void __cdecl i2c_write(unsigned int config_data)
{
  unsigned int send_counter; // [sp+40Ch] [bp+40Ch]

  send_counter = 0;
  while ( (read_axi_fpga(0xCu) & 0x80000000) == 0 )
    usleep(0x1388u);
  write_axi_fpga(0xCu, config_data);
}
