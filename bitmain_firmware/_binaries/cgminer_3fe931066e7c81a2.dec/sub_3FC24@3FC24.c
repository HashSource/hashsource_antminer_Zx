int sub_3FC24()
{
  char *v0; // r4
  int i; // r0
  int v2; // t1
  int v3; // r4
  int v4; // r5
  int result; // r0
  _BYTE v6[4]; // [sp+10h] [bp-1008h] BYREF
  __int16 v7; // [sp+14h] [bp-1004h]
  char v8; // [sp+16h] [bp-1002h] BYREF
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v6[0] = 85;
  v7 = 0;
  v6[2] = 5;
  v6[1] = -86;
  v6[3] = 21;
  v0 = v6;
  v8 = 26;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v2 )
  {
    sub_3C7B0(i);
    if ( v0 == &v8 )
      break;
    v2 = (unsigned __int8)*++v0;
  }
  usleep(0x186A0u);
  v3 = sub_3C7C8();
  v4 = sub_3C7C8();
  pthread_mutex_unlock(&stru_790A0);
  if ( v3 == 21 && v4 == 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s ok", "disable_PIC16F1704_dc_dc_new");
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
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x",
      "disable_PIC16F1704_dc_dc_new",
      dword_7909C,
      v3,
      v4);
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
