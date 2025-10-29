int __fastcall sub_42358(int a1, unsigned int a2)
{
  _DWORD v5[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v6; // [sp+14h] [bp-1008h]
  char v7; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v5[1] = 0;
  v6 = 0;
  v5[0] = 0;
  v7 = 0;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "chainid%d %s: core timeout = %08x", a1, "set_core_timeout_chain", a2);
    sub_385C8(5, s, 0);
  }
  dword_7398C = a2;
  sub_3CA8C((int)v5, 1, 0, 40, a2);
  sub_3BFB4(a1, v5, 0xBu);
  return sub_2A884();
}
