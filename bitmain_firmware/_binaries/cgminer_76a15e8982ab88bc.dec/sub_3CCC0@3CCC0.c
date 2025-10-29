int __fastcall sub_3CCC0(__int16 a1, __int16 a2)
{
  char *v2; // r4
  int i; // r0
  int v4; // t1
  int v5; // r4
  int v6; // r5
  int result; // r0
  _BYTE v8[7]; // [sp+10h] [bp-1008h] BYREF
  char v9; // [sp+17h] [bp-1001h] BYREF
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v8[4] = a1;
  v8[1] = -86;
  v8[3] = 1;
  v9 = a2 + a1 + 7;
  v2 = v8;
  v8[5] = a2;
  v8[6] = (unsigned __int16)(a2 + a1 + 7) >> 8;
  v8[0] = 85;
  v8[2] = 6;
  pthread_mutex_lock(&stru_75EE0);
  for ( i = 85; ; i = v4 )
  {
    sub_3C460(i);
    if ( v2 == &v9 )
      break;
    v4 = (unsigned __int8)*++v2;
  }
  usleep(0x186A0u);
  v5 = sub_3C478();
  v6 = sub_3C478();
  pthread_mutex_unlock(&stru_75EE0);
  if ( v5 == 1 && v6 == 1 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "%s ok", "set_PIC16F1704_flash_pointer_new");
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
      "set_PIC16F1704_flash_pointer_new",
      dword_75EDC,
      v5,
      v6);
    sub_385C8(3, s, 0);
    return 0;
  }
  return result;
}
