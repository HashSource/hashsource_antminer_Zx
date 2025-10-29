unsigned __int8 __fastcall asic_baud_to_fpga_baud(unsigned __int8 asic_baud)
{
  if ( asic_baud > 1u && asic_baud != 26 )
  {
    printf("%s: Don't support ASIC baud = %d, error!!!\n", "asic_baud_to_fpga_baud", asic_baud);
    return 53;
  }
  return asic_baud;
}
