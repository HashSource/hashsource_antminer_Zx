int __fastcall sub_3EA50(char a1, unsigned int a2)
{
  unsigned int v3; // r7
  int v4; // r8
  int v5; // r12
  char v7; // [sp+Ch] [bp-1018h]
  unsigned int v8; // [sp+10h] [bp-1014h]
  int v9; // [sp+14h] [bp-1010h]
  char v10; // [sp+1Bh] [bp-1009h] BYREF
  _BYTE v11[2]; // [sp+1Ch] [bp-1008h] BYREF
  unsigned __int16 v12; // [sp+1Eh] [bp-1006h] BYREF
  char s[4064]; // [sp+20h] [bp-1004h] BYREF

  if ( a2 - 700 > 0x64 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      v3 = 700;
      snprintf(s, 0x1000u, "illegal voltage [%d, %d], set default voltage %d\n", 700, 800, 700);
      sub_38730(5, s, 0);
      LOBYTE(v8) = 2;
      v9 = 704;
      v7 = -68;
    }
    else
    {
      v9 = 704;
      LOBYTE(v8) = 2;
      v7 = -68;
      v3 = 700;
    }
  }
  else
  {
    v3 = a2;
    v7 = a2;
    v8 = a2 >> 8;
    v9 = a2 + 4;
  }
  LOBYTE(v4) = 4;
  v12 = 0;
  while ( 1 )
  {
    v10 = -1;
    sub_3C7E0(a1, 0, (int)&v10, 1);
    sub_2A92C();
    v11[1] = v8;
    v11[0] = v7;
    sub_3C7E0(a1, 33, (int)v11, 2);
    sub_2A92C();
    sub_3E564(a1, &v12);
    v5 = v12;
    if ( v12 <= v9 && v12 >= (int)(v3 - 4) )
      break;
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "set vol %d, get vol %d, set again!\n", v3, v12);
      sub_38730(5, s, 0);
    }
    sub_2A92C();
    v4 = (unsigned __int8)(v4 - 1);
    if ( !v4 )
      return v12;
  }
  return v5;
}
