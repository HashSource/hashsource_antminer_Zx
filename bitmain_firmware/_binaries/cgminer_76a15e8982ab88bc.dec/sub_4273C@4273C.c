int __fastcall sub_4273C(int a1, int a2, int a3)
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
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "%s %d %d freq=%d\n", "set_freq_asic", a1, a2, a3);
    sub_385C8(7, s, 0);
  }
  v6 = 0;
  while ( 1 )
  {
    v7 = *(_DWORD *)&aD_0[16 * v6];
    v8 = 16 * v6++;
    if ( a3 == v7 )
      break;
    if ( v6 == 100 )
    {
      v8 = 64;
      break;
    }
  }
  sub_3CA8C((int)v10, 0, byte_9A4C7 * v4, 12, *(_DWORD *)&aResetAllHashBo[v8 + 2132]);
  sub_3BFB4(a1, v10, 0xBu);
  return sub_2A884();
}
