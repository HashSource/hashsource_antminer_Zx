int __fastcall sub_435E0(int a1, int a2)
{
  int v4; // r2
  int v5; // r12
  int v6; // lr
  _DWORD v8[2]; // [sp+Ch] [bp-100Ch] BYREF
  __int16 v9; // [sp+14h] [bp-1004h]
  char v10; // [sp+16h] [bp-1002h]
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v8[1] = 0;
  v8[0] = 0;
  v9 = 0;
  v10 = 0;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "chainid%d %s freq=%d", a1, "set_frequency_chain", a2);
    sub_38730(5, s, 0);
  }
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)&aD_0[16 * v4];
    v6 = 16 * v4++;
    if ( a2 == v5 )
      break;
    if ( v4 == 115 )
    {
      v6 = 64;
      break;
    }
  }
  dword_76B58 = *(_DWORD *)&aResetAllHashBo[v6 + 2232];
  sub_3CDCC((int)v8, 1, 0, 12, dword_76B58);
  sub_3C150(a1, v8, 0xBu);
  *(_WORD *)((char *)&unk_9D4B4 + 2 * a1 + 593) = a2;
  return sub_2A92C();
}
