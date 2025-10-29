void __fastcall set_fpga_baud(unsigned __int8 asic_baud)
{
  unsigned __int8 v1; // r0

  v1 = asic_baud_to_fpga_baud(asic_baud);
  axi_fpga_addr[15] = v1 & 0x3F | ((v1 & 0x3F) << 8) | ((v1 & 0x3F) << 16) & 0xC0FFFFFF | ((v1 & 0x3F) << 24);
}
