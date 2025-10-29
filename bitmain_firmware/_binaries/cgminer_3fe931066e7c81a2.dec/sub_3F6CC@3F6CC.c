int __fastcall sub_3F6CC(int a1)
{
  char *v2; // r4
  int i; // r0
  int v4; // t1
  char *v5; // r4
  int v6; // r5
  int result; // r0
  char v8; // r3
  int v9; // r6
  char *j; // r2
  char v11; // t1
  _BYTE v12[5]; // [sp+40h] [bp-1018h] BYREF
  char v13; // [sp+45h] [bp-1013h] BYREF
  char v14; // [sp+47h] [bp-1011h] BYREF
  int v15; // [sp+48h] [bp-1010h] BYREF
  int v16; // [sp+4Ch] [bp-100Ch]
  int v17; // [sp+50h] [bp-1008h]
  int v18; // [sp+54h] [bp-1004h] BYREF
  char s[4072]; // [sp+58h] [bp-1000h] BYREF

  v16 = 0;
  v15 = 255;
  v17 = 0;
  v18 = 0;
  v12[4] = 0;
  v12[1] = -86;
  v2 = v12;
  v12[2] = 4;
  v12[3] = 19;
  v13 = 23;
  v12[0] = 85;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C7B0(i);
    if ( v2 == &v13 )
      break;
    v4 = (unsigned __int8)*++v2;
  }
  usleep(0x30D40u);
  v5 = &v14;
  do
    *++v5 = sub_3C7C8();
  while ( v5 != (char *)&v18 + 3 );
  pthread_mutex_unlock(&stru_790A0);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    v6 = BYTE1(v15);
    snprintf(
      s,
      0x1000u,
      "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,\t\trea"
      "d_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,\t\tread_back_"
      "data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,\t\tread_back_data["
      "12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n",
      "read_hash_id_PIC16F1704_new",
      (unsigned __int8)v15,
      BYTE1(v15),
      BYTE2(v15),
      HIBYTE(v15),
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
    sub_38730(5, s, 0);
    if ( v6 != 19 )
      goto LABEL_9;
  }
  else if ( BYTE1(v15) != 19 )
  {
    goto LABEL_9;
  }
  if ( (unsigned __int8)v15 != 16 )
  {
LABEL_9:
    if ( !byte_7AD48 )
    {
      result = (unsigned __int8)byte_78E08;
      if ( !byte_78E08 && dword_766C4 <= 2 )
        return result;
    }
    snprintf(s, 0x1000u, aSChainDFailed_0, "read_hash_id_PIC16F1704_new", dword_7909C);
    goto LABEL_13;
  }
  v8 = BYTE2(v15);
  if ( BYTE2(v18) != (unsigned __int16)(BYTE1(v18)
                                      + (unsigned __int8)v18
                                      + HIBYTE(v17)
                                      + BYTE2(v17)
                                      + BYTE1(v17)
                                      + (unsigned __int8)v17
                                      + HIBYTE(v16)
                                      + BYTE2(v16)
                                      + BYTE1(v16)
                                      + (unsigned __int8)v16
                                      + BYTE2(v15)
                                      + HIBYTE(v15)
                                      + 35) >> 8
    || HIBYTE(v18) != (unsigned __int8)(BYTE1(v18)
                                      + v18
                                      + HIBYTE(v17)
                                      + BYTE2(v17)
                                      + BYTE1(v17)
                                      + v17
                                      + HIBYTE(v16)
                                      + BYTE2(v16)
                                      + BYTE1(v16)
                                      + v16
                                      + BYTE2(v15)
                                      + HIBYTE(v15)
                                      + 35) )
  {
    if ( !byte_7AD48 )
    {
      result = (unsigned __int8)byte_78E08;
      if ( !byte_78E08 && dword_766C4 <= 2 )
        return result;
    }
    snprintf(
      s,
      0x1000u,
      "%s failed! crc = 0x%04x",
      "read_hash_id_PIC16F1704_new",
      (unsigned __int16)(BYTE1(v18)
                       + (unsigned __int8)v18
                       + HIBYTE(v17)
                       + BYTE2(v17)
                       + BYTE1(v17)
                       + (unsigned __int8)v17
                       + HIBYTE(v16)
                       + BYTE2(v16)
                       + BYTE1(v16)
                       + (unsigned __int8)v16
                       + BYTE2(v15)
                       + HIBYTE(v15)
                       + 35));
LABEL_13:
    sub_38730(3, s, 0);
    return 0;
  }
  v9 = a1 - 1;
  for ( j = (char *)&v15 + 2; ; ++j )
  {
    *(_BYTE *)++v9 = v8;
    if ( j == (char *)&v18 + 1 )
      break;
    v11 = j[1];
    v8 = v11;
  }
  if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
    return 1;
  snprintf(s, 0x1000u, "%s ok", "read_hash_id_PIC16F1704_new");
  sub_38730(5, s, 0);
  return 1;
}
