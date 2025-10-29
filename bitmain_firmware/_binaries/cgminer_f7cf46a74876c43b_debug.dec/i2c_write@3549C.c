void __fastcall i2c_write(unsigned int config_data)
{
  int v2; // r4
  unsigned int v3; // r0

  v2 = 22;
  do
  {
    if ( (axi_fpga_addr[12] & 0x80000000) != 0 )
    {
      axi_fpga_addr[12] = config_data;
      return;
    }
    v3 = usleep(0x1388u);
    --v2;
  }
  while ( v2 );
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
    i2c_write_0(v3);
}
