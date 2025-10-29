int sub_3F64C()
{
  _WORD *v0; // r4
  int i; // r0
  int v2; // t1
  _WORD *v3; // r4
  int v4; // r4
  int result; // r0
  int v6; // [sp+14h] [bp-1014h] BYREF
  int v7; // [sp+18h] [bp-1010h]
  __int16 v8; // [sp+1Ch] [bp-100Ch] BYREF
  _BYTE v9[4]; // [sp+20h] [bp-1008h] BYREF
  __int16 v10; // [sp+24h] [bp-1004h] BYREF
  char s[4056]; // [sp+28h] [bp-1000h] BYREF

  v9[1] = -86;
  v7 = 255;
  v10 = 6656;
  v8 = 0;
  v9[2] = 4;
  v9[3] = 22;
  v0 = v9;
  v9[0] = 85;
  pthread_mutex_lock(&stru_75EE0);
  for ( i = 85; ; i = v2 )
  {
    sub_3C460(i);
    if ( v0 == (__int16 *)((char *)&v10 + 1) )
      break;
    v2 = *((unsigned __int8 *)v0 + 1);
    v0 = (_WORD *)((char *)v0 + 1);
  }
  usleep(0x186A0u);
  v3 = (_WORD *)((char *)&v6 + 3);
  do
  {
    *((_BYTE *)v3 + 1) = sub_3C478();
    v3 = (_WORD *)((char *)v3 + 1);
  }
  while ( v3 != (__int16 *)((char *)&v8 + 1) );
  pthread_mutex_unlock(&stru_75EE0);
  v4 = BYTE1(v7);
  if ( BYTE1(v7) == 22 && (result = BYTE2(v7), BYTE2(v7) == 1) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "%s ok", "heart_beat_PIC16F1704_new");
      sub_385C8(7, s, 0);
      return 1;
    }
  }
  else if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 2 )
  {
    snprintf(s, 0x1000u, "%s chain %d failed!", "heart_beat_PIC16F1704_new", dword_75EDC);
    sub_385C8(3, s, 0);
    if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 2 )
    {
      v6 = HIBYTE(v8);
      snprintf(
        s,
        0x1000u,
        "%s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n",
        "heart_beat_PIC16F1704_new",
        (unsigned __int8)v7,
        v4,
        BYTE2(v7),
        HIBYTE(v7),
        (unsigned __int8)v8,
        v6);
      sub_385C8(3, s, 0);
      return 0;
    }
  }
  return result;
}
