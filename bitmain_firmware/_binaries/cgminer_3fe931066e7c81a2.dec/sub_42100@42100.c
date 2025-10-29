int __fastcall sub_42100(void *a1, char a2, size_t a3)
{
  char *v5; // r4
  int i; // r0
  int v7; // t1
  int v8; // r5
  int v9; // r9
  int v10; // r4
  int v11; // r4
  int result; // r0
  __int16 v13; // r2
  signed int v14; // r3
  unsigned int v15; // r1
  _BYTE v16[7]; // [sp+8h] [bp-8h] BYREF
  char v17; // [sp+Fh] [bp-1h] BYREF
  _DWORD v18[10]; // [sp+10h] [bp+0h] BYREF
  char s[4040]; // [sp+38h] [bp+28h] BYREF

  v17 = a3 + 58;
  memset(&v18[1], 0, 36);
  v18[0] = 255;
  v16[6] = (unsigned __int16)(a3 + 58) >> 8;
  v16[4] = a2;
  v16[1] = -86;
  v5 = v16;
  v16[5] = a3;
  v16[2] = 6;
  v16[3] = 52;
  v16[0] = 85;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v7 )
  {
    sub_3C7B0(i);
    if ( v5 == &v17 )
      break;
    v7 = (unsigned __int8)*++v5;
  }
  usleep(0x30D40u);
  v8 = 0;
  v9 = a3 + 4;
  LOBYTE(v10) = 0;
  do
  {
    v10 = (unsigned __int8)(v10 + 1);
    *((_BYTE *)v18 + v8) = sub_3C7C8();
    v8 = v10;
  }
  while ( v10 <= v9 );
  v11 = BYTE1(v18[0]);
  pthread_mutex_unlock(&stru_790A0);
  if ( v11 != 52 )
    return 0;
  v13 = LOBYTE(v18[0]);
  if ( LOBYTE(v18[0]) != a3 + 5 || BYTE2(v18[0]) != 1 )
    return 0;
  LOBYTE(v14) = 0;
  LOWORD(v15) = 0;
  while ( 1 )
  {
    v14 = (unsigned __int8)(v14 + 1);
    v15 = (unsigned __int16)(v15 + v13);
    if ( v14 > (int)(a3 + 2) )
      break;
    v13 = *((unsigned __int8 *)v18 + v14);
  }
  if ( *((unsigned __int8 *)v18 + a3 + 3) == v15 >> 8 && *((unsigned __int8 *)v18 + v9) == (unsigned __int8)v15 )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "\n--- %s ok\n\n", "read_data_from_PIC16F1704_flash");
      sub_38730(7, s, 0);
    }
    memcpy(a1, (char *)v18 + 3, a3);
    return 1;
  }
  else if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 2 )
  {
    snprintf(s, 0x1000u, "\n--- %s failed! crc = 0x%04x\n\n", "read_data_from_PIC16F1704_flash", v15);
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
