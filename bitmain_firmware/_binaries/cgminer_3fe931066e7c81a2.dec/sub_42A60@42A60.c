int __fastcall sub_42A60(_BYTE *a1, int a2)
{
  int v2; // r2
  _BYTE *v4; // r2
  char v5; // r1
  unsigned int v6; // r3
  int v7; // t1
  char v8[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( a2 == 146 )
  {
    v4 = a1 + 2;
    v5 = a1[2];
    v6 = 0xFFFF;
    *a1 = 85;
    a1[2] = v5 & 0x1F | 0x20;
    a1[1] = -86;
    do
    {
      v7 = (unsigned __int8)*v4++;
      v6 = (unsigned __int16)(*(_WORD *)&aResetAllHashBo[2 * (v7 ^ (v6 >> 8)) + 404] ^ ((_WORD)v6 << 8));
    }
    while ( v4 != a1 + 144 );
    v2 = 146;
    *((_WORD *)a1 + 72) = (v6 >> 8) | ((_WORD)v6 << 8);
  }
  else if ( byte_7AD48 || (v2 = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 3 )
  {
    snprintf(v8, 0x1000u, "%s len error\n", "bm1740_makeup_work");
    sub_38730(4, v8, 0);
    return 0;
  }
  return v2;
}
