int __fastcall sub_41E7C(unsigned __int8 *src, char a2, signed int n)
{
  signed int v4; // r3
  __int16 v5; // r4
  __int16 v6; // r12
  char *v7; // r3
  int v8; // r6
  int v9; // r3
  unsigned __int8 i; // r4
  char *v11; // r4
  int result; // r0
  char v13; // [sp+13h] [bp-1021h] BYREF
  int v14; // [sp+14h] [bp-1020h]
  char v15; // [sp+18h] [bp-101Ch] BYREF
  _BYTE v16[20]; // [sp+1Ch] [bp-1018h] BYREF
  char s[4100]; // [sp+30h] [bp-1004h] BYREF

  v4 = 0;
  memset(&v16[4], 0, 13);
  v5 = 2 * n + 57;
  v14 = 255;
  v15 = 0;
  if ( n > 0 )
  {
    do
    {
      v6 = src[v4];
      v4 = (unsigned __int8)(v4 + 1);
      v5 += v6;
    }
    while ( n > v4 );
  }
  v16[4] = a2;
  v16[5] = n;
  v16[0] = 85;
  v16[2] = n + 6;
  v16[1] = -86;
  v16[3] = 51;
  memcpy(&v16[6], src, n);
  v7 = &s[n + 4096];
  v8 = n + 8;
  v7 -= 4096;
  *(v7 - 13) = v5;
  *(v7 - 14) = HIBYTE(v5);
  pthread_mutex_lock(&stru_790A0);
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( i = 0; i < v8; v9 = ++i )
      sub_3C7B0((unsigned __int8)v16[v9]);
  }
  usleep(0x30D40u);
  v11 = &v13;
  do
    *++v11 = sub_3C7C8();
  while ( v11 != &v15 );
  pthread_mutex_unlock(&stru_790A0);
  if ( (unsigned __int8)v14 == 5 && BYTE1(v14) == 51 && (result = BYTE2(v14), BYTE2(v14) == 1) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "\n--- %s ok\n\n", "write_data_to_PIC16F1704_flash");
      sub_38730(7, s, 0);
      return 1;
    }
  }
  else if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n",
      "write_data_to_PIC16F1704_flash",
      (unsigned __int8)v14,
      BYTE1(v14),
      BYTE2(v14));
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
