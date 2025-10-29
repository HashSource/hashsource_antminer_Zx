int __fastcall sub_3ECB8(char a1, int a2)
{
  __int16 v2; // r5
  int v4; // r3
  int v6; // r6
  char v7; // [sp+Bh] [bp-1009h] BYREF
  char v8; // [sp+Ch] [bp-1008h] BYREF
  char v9; // [sp+Dh] [bp-1007h] BYREF
  unsigned __int16 v10; // [sp+Eh] [bp-1006h] BYREF
  char s[4080]; // [sp+10h] [bp-1004h] BYREF

  v2 = a2;
  if ( (unsigned int)(a2 - 700) <= 0x64 )
  {
    v7 = -1;
    sub_3C7E0(a1, 0, (int)&v7, 1);
    v8 = 26;
    sub_3C7E0(a1, 2, (int)&v8, 1);
    sub_2A92C();
    v9 = 64;
    sub_3C7E0(a1, 1, (int)&v9, 1);
    sub_2A92C();
    *(_WORD *)s = v2;
    sub_3C7E0(a1, 33, (int)s, 2);
    sub_2A92C();
    v9 = 0x80;
    sub_3C7E0(a1, 1, (int)&v9, 1);
    sub_2A92C();
    LOBYTE(v6) = 5;
    v10 = 0;
    sub_2A92C();
    sub_3E564(a1, &v10);
    while ( 1 )
    {
      v4 = v10;
      if ( v10 )
        break;
      sub_2A92C();
      sub_3E564(a1, &v10);
      v6 = (unsigned __int8)(v6 - 1);
      if ( !v6 )
        return v10;
    }
  }
  else if ( byte_7AD48 || (v4 = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "illegal voltage [%d, %d]\n", 700, 800);
    sub_38730(5, s, 0);
    return 0;
  }
  return v4;
}
