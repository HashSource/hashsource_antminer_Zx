int sub_3DDD0()
{
  char *v0; // r4
  int i; // r0
  int v2; // t1
  int v3; // r4
  int v4; // r5
  int result; // r0
  _BYTE v6[5]; // [sp+10h] [bp-1008h] BYREF
  char v7; // [sp+15h] [bp-1003h] BYREF
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v6[0] = 85;
  v0 = v6;
  v6[4] = 0;
  v6[1] = -86;
  v6[2] = 4;
  v6[3] = 6;
  v7 = 10;
  pthread_mutex_lock(&stru_790A0);
  for ( i = 85; ; i = v2 )
  {
    sub_3C7B0(i);
    if ( v0 == &v7 )
      break;
    v2 = (unsigned __int8)*++v0;
  }
  usleep(0x186A0u);
  v3 = sub_3C7C8();
  v4 = sub_3C7C8();
  pthread_mutex_unlock(&stru_790A0);
  usleep(0x493E0u);
  if ( v3 == 6 && v4 == 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s ok", "jump_from_loader_to_app_PIC16F1704_new");
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
      "jump_from_loader_to_app_PIC16F1704_new",
      dword_7909C,
      v3,
      v4);
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
