int __fastcall sub_431AC(int a1, int a2)
{
  unsigned int v3; // r4
  _DWORD v5[2]; // [sp+Ch] [bp-100Ch] BYREF
  __int16 v6; // [sp+14h] [bp-1004h]
  char v7; // [sp+16h] [bp-1002h]
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v5[1] = 0;
  v6 = 0;
  v5[0] = 0;
  v3 = (unsigned __int8)a2 << 27;
  v7 = 0;
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "chainid%d %s: nonce shift = %08x", a1, "set_nonce_shift_chain", a2);
    sub_38730(7, s, 0);
  }
  dword_76B50 = v3;
  sub_3CDCC((int)v5, 1, 0, 80, v3);
  sub_3C150(a1, v5, 0xBu);
  return sub_2A92C();
}
