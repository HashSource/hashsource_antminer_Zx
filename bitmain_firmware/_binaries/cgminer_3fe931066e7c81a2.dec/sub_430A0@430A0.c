int __fastcall sub_430A0(int a1, unsigned int a2)
{
  _DWORD v5[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v6; // [sp+14h] [bp-1008h]
  char v7; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v5[1] = 0;
  v6 = 0;
  v5[0] = 0;
  v7 = 0;
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "chainid%d %s: core timeout = %08x", a1, "set_core_timeout_chain", a2);
    sub_38730(7, s, 0);
  }
  dword_76B4C = a2;
  sub_3CDCC((int)v5, 1, 0, 40, a2);
  sub_3C150(a1, v5, 0xBu);
  return sub_2A92C();
}
