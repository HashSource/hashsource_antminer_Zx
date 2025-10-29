int __fastcall sub_3F9B0(_BYTE *a1)
{
  char *v2; // r4
  int i; // r0
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r5
  int v8; // r2
  unsigned int v9; // r3
  char v10; // [sp+17h] [bp-1015h] BYREF
  int v11; // [sp+18h] [bp-1014h]
  unsigned __int8 v12; // [sp+1Ch] [bp-1010h] BYREF
  _BYTE v13[5]; // [sp+20h] [bp-100Ch] BYREF
  char v14; // [sp+25h] [bp-1007h] BYREF
  char s[4056]; // [sp+28h] [bp-1004h] BYREF

  v13[1] = -86;
  v11 = 255;
  v13[4] = 0;
  v12 = 0;
  v2 = v13;
  v13[2] = 4;
  v13[3] = 23;
  v14 = 27;
  v13[0] = 85;
  pthread_mutex_lock(&stru_75EE0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C460(i);
    if ( v2 == &v14 )
      break;
    v4 = (unsigned __int8)*++v2;
  }
  usleep((__useconds_t)"-P");
  v5 = (unsigned __int8 *)&v10;
  do
    *++v5 = sub_3C478();
  while ( v5 != &v12 );
  pthread_mutex_unlock(&stru_75EE0);
  if ( byte_75C49 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
    {
      v6 = BYTE1(v11);
      snprintf(
        s,
        0x1000u,
        "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read"
        "_back_data[4] = 0x%x",
        "get_PIC16F1704_software_version_new",
        (unsigned __int8)v11,
        BYTE1(v11),
        BYTE2(v11),
        HIBYTE(v11),
        v12);
      sub_385C8(7, s, 0);
      if ( v6 != 23 )
        goto LABEL_9;
      goto LABEL_25;
    }
    v6 = BYTE1(v11);
  }
  else
  {
    v6 = BYTE1(v11);
  }
  if ( v6 != 23 )
  {
LABEL_9:
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
      return 0;
    snprintf(s, 0x1000u, "%s chain %d failed!", "get_PIC16F1704_software_version_new", dword_75EDC);
    sub_385C8(3, s, 0);
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
      return 0;
    snprintf(
      s,
      0x1000u,
      "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_b"
      "ack_data[4] = 0x%x",
      "get_PIC16F1704_software_version_new",
      (unsigned __int8)v11,
      v6,
      BYTE2(v11),
      HIBYTE(v11),
      v12);
    goto LABEL_14;
  }
LABEL_25:
  if ( (unsigned __int8)v11 != 5 )
    goto LABEL_9;
  v8 = BYTE2(v11);
  v9 = BYTE2(v11) + 28;
  if ( HIBYTE(v11) != v9 >> 8 || v12 != (unsigned __int8)v9 )
  {
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
      return 0;
    snprintf(s, 0x1000u, "%s failed! crc = 0x%04x", "get_PIC16F1704_software_version_new", BYTE2(v11) + 28);
LABEL_14:
    sub_385C8(3, s, 0);
    return 0;
  }
  *a1 = BYTE2(v11);
  if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
    return 1;
  snprintf(s, 0x1000u, "%s ok, version = 0x%02x", "get_PIC16F1704_software_version_new", v8);
  sub_385C8(5, s, 0);
  return 1;
}
