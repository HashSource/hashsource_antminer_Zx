int __fastcall sub_41B8C(_WORD *a1)
{
  char *v2; // r4
  int i; // r0
  int v4; // t1
  char *v5; // r4
  int v6; // r5
  int result; // r0
  unsigned int v8; // r3
  int v9; // r2
  char v10; // [sp+17h] [bp-1015h] BYREF
  int v11; // [sp+18h] [bp-1014h]
  __int16 v12; // [sp+1Ch] [bp-1010h] BYREF
  _BYTE v13[3]; // [sp+20h] [bp-100Ch] BYREF
  char v14[5]; // [sp+23h] [bp-1009h] BYREF
  char s[4056]; // [sp+28h] [bp-1004h] BYREF

  v13[1] = -86;
  v11 = 255;
  v12 = 0;
  v2 = v13;
  v13[2] = 4;
  strcpy(v14, "%");
  v14[2] = 41;
  v13[0] = 85;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C7B0(i);
    if ( v2 == &v14[2] )
      break;
    v4 = (unsigned __int8)*++v2;
  }
  usleep(0x493E0u);
  v5 = &v10;
  do
    *++v5 = sub_3C7C8();
  while ( v5 != (char *)&v12 + 1 );
  pthread_mutex_unlock(&stru_790A0);
  usleep(0x30D40u);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    v6 = BYTE1(v11);
    snprintf(
      s,
      0x1000u,
      "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, re"
      "ad_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n",
      "get_PIC16F1704_freq_new",
      (unsigned __int8)v11,
      BYTE1(v11),
      BYTE2(v11),
      HIBYTE(v11),
      (unsigned __int8)v12,
      HIBYTE(v12));
    sub_38730(5, s, 0);
    if ( v6 != 37 )
      goto LABEL_9;
  }
  else if ( BYTE1(v11) != 37 )
  {
    goto LABEL_9;
  }
  if ( (unsigned __int8)v11 != 6 )
  {
LABEL_9:
    if ( !byte_7AD48 )
    {
      result = (unsigned __int8)byte_78E08;
      if ( !byte_78E08 && dword_766C4 <= 2 )
        return result;
    }
    snprintf(s, 0x1000u, "\n--- %s failed!\n\n", "get_PIC16F1704_freq_new");
    goto LABEL_13;
  }
  v8 = BYTE2(v11) + HIBYTE(v11) + 43;
  if ( (unsigned __int8)v12 != v8 >> 8 || HIBYTE(v12) != (unsigned __int8)v8 )
  {
    if ( !byte_7AD48 )
    {
      result = (unsigned __int8)byte_78E08;
      if ( !byte_78E08 && dword_766C4 <= 2 )
        return result;
    }
    snprintf(s, 0x1000u, "\n--- %s failed! crc = 0x%04x\n\n", "get_PIC16F1704_freq_new", BYTE2(v11) + HIBYTE(v11) + 43);
LABEL_13:
    sub_38730(3, s, 0);
    return 0;
  }
  v9 = HIBYTE(v11) | (BYTE2(v11) << 8);
  *a1 = _byteswap_ushort(HIWORD(v11));
  if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
    return 1;
  snprintf(s, 0x1000u, "\n--- %s ok, freq = %d\n\n", "get_PIC16F1704_freq_new", v9);
  sub_38730(5, s, 0);
  return 1;
}
