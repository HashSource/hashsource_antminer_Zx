void __fastcall sub_4886C(int a1, int a2, char a3, unsigned int a4)
{
  unsigned int v8; // r9
  int v9; // r4
  char *v10; // r9
  _DWORD v11[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v12; // [sp+14h] [bp-1008h]
  char v13; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v11[1] = 0;
  v12 = 0;
  v11[0] = 0;
  v13 = 0;
  sub_2A92C();
  if ( a4 < 2 )
  {
    v8 = a4;
  }
  else if ( a4 == 17 )
  {
    v8 = 2;
  }
  else
  {
    if ( a4 != 254 )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
      {
        snprintf(s, 0x1000u, "%s unknow reg_type %d\n", "read_i2c_reg", a4);
        sub_38730(4, s, 0);
      }
      return;
    }
    v8 = 3;
  }
  v9 = 3;
  sub_3CDCC(
    (int)v11,
    0,
    *((_BYTE *)&dword_78E10[200] + a2),
    32,
    dword_76B6C & 0xFE000000 | 0x1000000 | ((a3 & 0x7F) << 17) | (unsigned __int16)((unsigned __int8)a4 << 8));
  sub_3C150(a1, v11, 0xBu);
  sub_2A92C();
  v10 = (char *)&dword_78E10[3 * a1 + a2] + v8;
  v10[3492] = 0;
  do
  {
    sub_2A92C();
    sub_481EC(a1, *((unsigned __int8 *)&dword_78E10[200] + a2), 32, 0);
    if ( v10[3492] )
      break;
    --v9;
  }
  while ( v9 );
}
