int __fastcall sub_419C8(unsigned int a1)
{
  char *v1; // r4
  int i; // r0
  int v3; // t1
  int v4; // r4
  int v5; // r5
  int result; // r0
  _BYTE v7[7]; // [sp+8h] [bp-1008h] BYREF
  char v8; // [sp+Fh] [bp-1001h] BYREF
  char s[4080]; // [sp+10h] [bp-1000h] BYREF

  v7[5] = a1;
  v7[1] = -86;
  v7[3] = 36;
  v8 = BYTE1(a1) + a1 + 42;
  v7[4] = BYTE1(a1);
  v7[6] = (unsigned __int16)((a1 >> 8) + (unsigned __int8)a1 + 42) >> 8;
  v1 = v7;
  v7[0] = 85;
  v7[2] = 6;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v3 )
  {
    sub_3C7B0(i);
    if ( v1 == &v8 )
      break;
    v3 = (unsigned __int8)*++v1;
  }
  usleep(0x493E0u);
  v4 = sub_3C7C8();
  v5 = sub_3C7C8();
  pthread_mutex_unlock(&stru_790A0);
  usleep(0x30D40u);
  if ( v4 == 36 && v5 == 1 )
  {
    if ( byte_78E09 )
    {
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        return 1;
      snprintf(s, 0x1000u, "\n--- %s ok\n\n", "save_freq_PIC16F1704_new");
      sub_38730(7, s, 0);
    }
    return 1;
  }
  else if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
      "save_freq_PIC16F1704_new",
      v4,
      v5);
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
