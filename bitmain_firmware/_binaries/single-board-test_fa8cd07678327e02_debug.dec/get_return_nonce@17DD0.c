void __cdecl get_return_nonce(unsigned int *buf)
{
  *buf = read_axi_fpga(4u);
  buf[1] = read_axi_fpga(5u);
}
