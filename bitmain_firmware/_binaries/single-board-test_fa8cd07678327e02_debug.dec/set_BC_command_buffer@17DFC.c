void __cdecl set_BC_command_buffer(unsigned int *value)
{
  write_axi_fpga(0x31u, *value);
  write_axi_fpga(0x32u, value[1]);
  write_axi_fpga(0x33u, value[2]);
}
