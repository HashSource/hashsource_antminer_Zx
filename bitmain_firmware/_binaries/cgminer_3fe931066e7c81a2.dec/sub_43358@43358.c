int __fastcall sub_43358(int a1)
{
  int v2; // r4
  _DWORD v4[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v5; // [sp+14h] [bp-1008h]
  char v6; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v4[1] = 0;
  v4[0] = 0;
  v5 = 0;
  v2 = dword_76B54 & 0xFFFF0FFF | 0x3000;
  v6 = 0;
  dword_76B54 = v2;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "chainid%d %s: IO drive = %08x", a1, "set_io_drive_strength_chain", v2);
    sub_38730(5, s, 0);
  }
  sub_3CDCC((int)v4, 1, 0, 48, v2);
  sub_3C150(a1, v4, 0xBu);
  return sub_2A92C();
}
