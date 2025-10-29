unsigned __int8 __fastcall asic_baud_to_fpga_baud(unsigned __int8 asic_baud)
{
  int v1; // r2
  const char *v2; // r0

  v1 = asic_baud;
  if ( asic_baud > 1u && asic_baud != 26 )
  {
    LOWORD(v2) = -31400;
    HIWORD(v2) = (unsigned int)"dr failed. fpga_mem_addr = 0x%x\n" >> 16;
    printf(v2, "asic_baud_to_fpga_baud", v1);
    return 53;
  }
  return asic_baud;
}
