int __fastcall sub_40214(int a1)
{
  char *v2; // r4
  int i; // r0
  int v4; // t1
  char *v5; // r4
  int v6; // r5
  int result; // r0
  char v8; // r3
  unsigned int v9; // r2
  int v10; // r6
  char *j; // r2
  char v12; // t1
  _BYTE v13[3]; // [sp+34h] [bp-1014h] BYREF
  char v14[4]; // [sp+37h] [bp-1011h] BYREF
  char v15; // [sp+3Bh] [bp-100Dh] BYREF
  int v16; // [sp+3Ch] [bp-100Ch] BYREF
  int v17; // [sp+40h] [bp-1008h]
  int v18; // [sp+44h] [bp-1004h] BYREF
  char s[4088]; // [sp+48h] [bp-1000h] BYREF

  v17 = 0;
  v18 = 0;
  v16 = 255;
  v13[2] = 4;
  v13[1] = -86;
  v2 = v13;
  strcpy(v14, "#");
  v14[2] = 39;
  v13[0] = 85;
  pthread_mutex_lock(&stru_75EE0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C460(i);
    if ( v2 == &v14[2] )
      break;
    v4 = (unsigned __int8)*++v2;
  }
  usleep(0x30D40u);
  v5 = &v15;
  do
    *++v5 = sub_3C478();
  while ( v5 != (char *)&v18 + 3 );
  pthread_mutex_unlock(&stru_75EE0);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    v6 = BYTE1(v16);
    snprintf(
      s,
      0x1000u,
      "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, \t\tre"
      "ad_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_bac"
      "k_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n",
      "read_temperature_offset_PIC16F1704_new",
      (unsigned __int8)v16,
      BYTE1(v16),
      BYTE2(v16),
      HIBYTE(v16),
      (unsigned __int8)v17,
      BYTE1(v17),
      BYTE2(v17),
      HIBYTE(v17),
      (unsigned __int8)v18,
      BYTE1(v18),
      BYTE2(v18),
      HIBYTE(v18));
    sub_385C8(5, s, 0);
    if ( v6 != 35 )
      goto LABEL_9;
  }
  else if ( BYTE1(v16) != 35 )
  {
    goto LABEL_9;
  }
  if ( (unsigned __int8)v16 != 12 )
  {
LABEL_9:
    if ( !byte_77B70 )
    {
      result = (unsigned __int8)byte_75C48;
      if ( !byte_75C48 && dword_73504 <= 2 )
        return result;
    }
    snprintf(s, 0x1000u, "%s failed!", "read_temperature_offset_PIC16F1704_new");
    goto LABEL_13;
  }
  v8 = BYTE2(v16);
  v9 = BYTE1(v18)
     + (unsigned __int8)v18
     + HIBYTE(v17)
     + BYTE2(v17)
     + BYTE1(v17)
     + (unsigned __int8)v17
     + BYTE2(v16)
     + HIBYTE(v16)
     + 47;
  if ( BYTE2(v18) != v9 >> 8 || HIBYTE(v18) != (unsigned __int8)v9 )
  {
    if ( !byte_77B70 )
    {
      result = (unsigned __int8)byte_75C48;
      if ( !byte_75C48 && dword_73504 <= 2 )
        return result;
    }
    snprintf(
      s,
      0x1000u,
      "%s failed! crc = 0x%04x",
      "read_temperature_offset_PIC16F1704_new",
      BYTE1(v18)
    + (unsigned __int8)v18
    + HIBYTE(v17)
    + BYTE2(v17)
    + BYTE1(v17)
    + (unsigned __int8)v17
    + BYTE2(v16)
    + HIBYTE(v16)
    + 47);
LABEL_13:
    sub_385C8(3, s, 0);
    return 0;
  }
  v10 = a1 - 1;
  for ( j = (char *)&v16 + 2; ; ++j )
  {
    *(_BYTE *)++v10 = v8;
    if ( j == (char *)&v18 + 1 )
      break;
    v12 = j[1];
    v8 = v12;
  }
  if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
    return 1;
  snprintf(s, 0x1000u, "%s ok", "read_temperature_offset_PIC16F1704_new");
  sub_385C8(5, s, 0);
  return 1;
}
