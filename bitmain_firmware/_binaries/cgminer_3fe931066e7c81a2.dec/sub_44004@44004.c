int __fastcall sub_44004(int a1, int a2)
{
  unsigned __int8 v3; // r5
  _DWORD v5[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v6; // [sp+14h] [bp-1008h]
  char v7; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v3 = a2;
  v5[1] = 0;
  v5[0] = 0;
  v6 = 0;
  v7 = 0;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s chainID%d ticket_mask = 0x%08x", "set_ticket_mask_chain", a1, a2);
    sub_38730(5, s, 0);
  }
  dword_76B60 = v3;
  sub_3CDCC((int)v5, 1, 0, 20, v3);
  sub_3C150(a1, v5, 0xBu);
  return sub_2A92C();
}
