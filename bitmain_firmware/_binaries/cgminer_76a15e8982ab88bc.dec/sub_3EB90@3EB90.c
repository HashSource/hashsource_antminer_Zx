int __fastcall sub_3EB90(int a1)
{
  char *v1; // r4
  int i; // r0
  int v4; // t1
  int v5; // r4
  int v6; // r5
  int result; // r0
  _BYTE v8[6]; // [sp+10h] [bp-100Ch] BYREF
  char v9; // [sp+16h] [bp-1006h] BYREF
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v9 = a1 + 21;
  v8[3] = 16;
  v1 = v8;
  v8[5] = (unsigned __int16)(a1 + 21) >> 8;
  v8[4] = a1;
  v8[1] = -86;
  v8[0] = 85;
  v8[2] = 5;
  pthread_mutex_lock(&stru_75EE0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C460(i);
    if ( v1 == &v9 )
      break;
    v4 = (unsigned __int8)*++v1;
  }
  usleep(0x30D40u);
  v5 = sub_3C478();
  v6 = sub_3C478();
  pthread_mutex_unlock(&stru_75EE0);
  usleep(0x30D40u);
  if ( v5 == 16 && v6 == 1 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "%s ok, voltage = 0x%02x", "set_PIC16F1704_voltage_new", a1);
      sub_385C8(5, s, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
      "set_PIC16F1704_voltage_new",
      dword_75EDC,
      v5,
      v6);
    sub_385C8(3, s, 0);
    return 0;
  }
  return result;
}
