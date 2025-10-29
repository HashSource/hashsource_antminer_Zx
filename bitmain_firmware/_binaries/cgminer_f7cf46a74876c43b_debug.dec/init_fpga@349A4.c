void init_fpga()
{
  printf("\n--- %s\n", "init_fpga");
  axi_fpga_addr[32] = -2139062257;
  do
    cgsleep_us(10000);
  while ( (axi_fpga_addr[32] & 0x80000000) != 0 );
  check_fpga_version();
  cgsleep_us((unsigned int)&loc_1869E + 2);
}
