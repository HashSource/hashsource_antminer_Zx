int __fastcall sub_40888(int a1)
{
  int v1; // r3
  __int16 v2; // r2
  __int16 v3; // r12
  int v4; // r1
  _DWORD *v5; // r3
  char v6; // t1
  char *v7; // r4
  int v8; // t1
  int v9; // r4
  int v10; // r5
  int result; // r0
  char v12; // [sp+7h] [bp-1011h] BYREF
  _DWORD v13[2]; // [sp+8h] [bp-1010h] BYREF
  int v14; // [sp+10h] [bp-1008h] BYREF
  __int16 v15; // [sp+14h] [bp-1004h] BYREF
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v1 = 0;
  v2 = 46;
  v13[1] = 0;
  v13[0] = 0;
  v14 = 0;
  v15 = 0;
  do
  {
    v3 = *(unsigned __int8 *)(a1 + v1++);
    v2 += v3;
  }
  while ( v1 != 8 );
  v4 = a1 - 1;
  v5 = (_DWORD *)((char *)v13 + 3);
  v13[0] = 571255381;
  do
  {
    v6 = *(_BYTE *)++v4;
    *((_BYTE *)v5 + 1) = v6;
    v5 = (_DWORD *)((char *)v5 + 1);
  }
  while ( v5 != (int *)((char *)&v14 + 3) );
  LOBYTE(v15) = HIBYTE(v2);
  v7 = &v12;
  HIBYTE(v15) = v2;
  pthread_mutex_lock(&stru_790A0);
  do
  {
    v8 = (unsigned __int8)*++v7;
    sub_3C7B0(v8);
  }
  while ( v7 != (char *)&v15 + 1 );
  usleep(0x30D40u);
  v9 = sub_3C7C8();
  v10 = sub_3C7C8();
  pthread_mutex_unlock(&stru_790A0);
  usleep(0x30D40u);
  if ( v9 == 34 && v10 == 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s ok", "write_temperature_offset_PIC16F1704_new");
      sub_38730(5, s, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x",
      "write_temperature_offset_PIC16F1704_new",
      v9,
      v10);
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
