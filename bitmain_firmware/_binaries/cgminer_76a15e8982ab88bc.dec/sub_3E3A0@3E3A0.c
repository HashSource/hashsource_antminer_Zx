int __fastcall sub_3E3A0(char a1, unsigned int a2)
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

  if ( a2 - 800 > 0x50 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      v3 = 840;
      snprintf(s, 0x1000u, "illegal voltage [%d, %d], set default voltage %d\n", 800, 880, 840);
      sub_385C8(5, s, 0);
      LOBYTE(v8) = 3;
      v9 = 844;
      v7 = 72;
    }
    else
    {
      v9 = 844;
      LOBYTE(v8) = 3;
      v7 = 72;
      v3 = 840;
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
    sub_3C490(a1, 0, (int)&v10, 1);
    sub_2A884();
    v11[1] = v8;
    v11[0] = v7;
    sub_3C490(a1, 33, (int)v11, 2);
    sub_2A884();
    sub_2A884();
    sub_3E224(a1, &v12);
    v5 = v12;
    if ( v12 <= v9 && v12 >= (int)(v3 - 4) )
      break;
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "set vol %d, get vol %d, set again!\n", v3, v12);
      sub_385C8(5, s, 0);
    }
    sub_2A884();
    v4 = (unsigned __int8)(v4 - 1);
    if ( !v4 )
      return v12;
  }
  return v5;
}
