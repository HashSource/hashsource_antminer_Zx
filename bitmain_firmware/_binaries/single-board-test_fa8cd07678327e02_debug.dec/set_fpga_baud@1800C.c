void __cdecl set_fpga_baud(unsigned __int8 asic_baud)
{
  unsigned __int8 fpga_baud; // [sp+Fh] [bp+Fh]

  fpga_baud = asic_baud_to_fpga_baud(asic_baud);
  write_axi_fpga(0xFu, fpga_baud);
}
