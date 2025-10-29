void init_fpga()
{
  const char *v0; // r0

  LOWORD(v0) = -31412;
  HIWORD(v0) = (unsigned int)" fpga_mem_addr failed. fpga_mem_addr = 0x%x\n" >> 16;
  printf(v0, "init_fpga");
  axi_fpga_addr[32] = -2139062257;
  do
    cgsleep_us(10000);
  while ( (axi_fpga_addr[32] & 0x80000000) != 0 );
  check_fpga_version();
  cgsleep_us((unsigned int)&loc_1869E + 2);
}
