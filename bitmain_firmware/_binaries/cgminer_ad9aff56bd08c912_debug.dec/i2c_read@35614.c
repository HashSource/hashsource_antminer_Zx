unsigned __int8 __fastcall i2c_read(unsigned int config_data)
{
  int v1; // r4

  v1 = 22;
  i2c_write(config_data | 0x2000000);
  do
  {
    usleep(0x1388u);
    if ( (axi_fpga_addr[12] & 0x80000000) != 0 )
      return axi_fpga_addr[12];
    --v1;
  }
  while ( v1 );
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
    return i2c_read_0(axi_fpga_addr[12]);
  else
    return -1;
}
