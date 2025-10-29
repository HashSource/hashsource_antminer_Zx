int __fastcall sub_40128(_BYTE *a1)
{
  char *v2; // r4
  int i; // r0
  int v4; // t1
  unsigned __int8 *v5; // r4
  int v6; // r4
  unsigned int v7; // r3
  char v9; // [sp+17h] [bp-1015h] BYREF
  int v10; // [sp+18h] [bp-1014h]
  unsigned __int8 v11; // [sp+1Ch] [bp-1010h] BYREF
  _BYTE v12[5]; // [sp+20h] [bp-100Ch] BYREF
  char v13; // [sp+25h] [bp-1007h] BYREF
  char s[4056]; // [sp+28h] [bp-1004h] BYREF

  v12[1] = -86;
  v10 = 255;
  v12[4] = 0;
  v11 = 0;
  v2 = v12;
  v12[2] = 4;
  v12[3] = 23;
  v13 = 27;
  v12[0] = 85;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C7B0(i);
    if ( v2 == &v13 )
      break;
    v4 = (unsigned __int8)*++v2;
  }
  usleep((__useconds_t)"n network");
  v5 = (unsigned __int8 *)&v9;
  do
    *++v5 = sub_3C7C8();
  while ( v5 != &v11 );
  pthread_mutex_unlock(&stru_790A0);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    v6 = BYTE1(v10);
    snprintf(
      s,
      0x1000u,
      "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_b"
      "ack_data[4] = 0x%x",
      "get_PIC16F1704_software_version_new",
      (unsigned __int8)v10,
      BYTE1(v10),
      BYTE2(v10),
      HIBYTE(v10),
      v11);
    sub_38730(7, s, 0);
    if ( v6 != 23 )
    {
LABEL_18:
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
        return 0;
      snprintf(s, 0x1000u, "%s chain %d failed!", "get_PIC16F1704_software_version_new", dword_7909C);
      sub_38730(3, s, 0);
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
        return 0;
      snprintf(
        s,
        0x1000u,
        "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read"
        "_back_data[4] = 0x%x",
        "get_PIC16F1704_software_version_new",
        (unsigned __int8)v10,
        v6,
        BYTE2(v10),
        HIBYTE(v10),
        v11);
      goto LABEL_23;
    }
  }
  else
  {
    v6 = BYTE1(v10);
    if ( BYTE1(v10) != 23 )
      goto LABEL_18;
  }
  if ( (unsigned __int8)v10 != 5 )
    goto LABEL_18;
  v7 = BYTE2(v10) + 28;
  if ( HIBYTE(v10) != v7 >> 8 || v11 != (unsigned __int8)v7 )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
      return 0;
    snprintf(s, 0x1000u, "%s failed! crc = 0x%04x", "get_PIC16F1704_software_version_new", BYTE2(v10) + 28);
LABEL_23:
    sub_38730(3, s, 0);
    return 0;
  }
  *a1 = BYTE2(v10);
  return 1;
}
