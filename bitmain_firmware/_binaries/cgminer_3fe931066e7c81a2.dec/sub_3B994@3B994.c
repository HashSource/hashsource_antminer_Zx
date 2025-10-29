void sub_3B994()
{
  char s[4088]; // [sp+8h] [bp-1000h] BYREF

  *(_DWORD *)dword_78E10[0] |= 0x60000000u;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "FPGA version: %04X", (unsigned __int16)*(_DWORD *)dword_78E10[0]);
    sub_38730(5, s, 0);
  }
}
