unsigned int get_BC_write_command()
{
  return read_axi_fpga(0x30u);
}
