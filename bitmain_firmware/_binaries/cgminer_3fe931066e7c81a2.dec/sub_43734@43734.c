int __fastcall sub_43734(int a1, int a2, int a3)
{
  char v4; // r6
  int v6; // r3
  int v7; // r12
  int v8; // r2
  _DWORD v10[2]; // [sp+14h] [bp-100Ch] BYREF
  __int16 v11; // [sp+1Ch] [bp-1004h]
  char v12; // [sp+1Eh] [bp-1002h]
  char s[4064]; // [sp+20h] [bp-1000h] BYREF

  v4 = a2;
  v10[1] = 0;
  v10[0] = 0;
  v11 = 0;
  v12 = 0;
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "%s %d %d freq=%d\n", "set_freq_asic", a1, a2, a3);
    sub_38730(7, s, 0);
  }
  v6 = 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)&aD_0[16 * v6];
    v8 = 16 * v6++;
    if ( a3 == v7 )
      break;
    if ( v6 == 115 )
    {
      v8 = 64;
      break;
    }
  }
  sub_3CDCC((int)v10, 0, byte_9D6F3 * v4, 12, *(_DWORD *)&aResetAllHashBo[v8 + 2232]);
  sub_3C150(a1, v10, 0xBu);
  return sub_2A92C();
}
