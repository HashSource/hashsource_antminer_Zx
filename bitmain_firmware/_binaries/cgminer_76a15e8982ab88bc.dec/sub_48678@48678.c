int sub_48678()
{
  int v0; // r4
  int v2; // r5
  char s[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( (unsigned __int8)byte_9A4A0 <= 1u )
  {
    v0 = 1;
    goto LABEL_12;
  }
  if ( dword_9A2BC != 1 )
    goto LABEL_6;
  if ( dword_9A471 < (unsigned int)((unsigned __int64)(12686672634000LL * (unsigned __int8)dword_9A4CC) >> 32) >> 6 )
  {
    v0 = 2;
    goto LABEL_12;
  }
  if ( byte_9A49E != 100 || (unsigned int)dword_9A471 > 0x1517 )
  {
LABEL_6:
    if ( dword_9A2BC != 2 )
    {
LABEL_7:
      v0 = 0;
      dword_75F60 = 0;
      return v0;
    }
    if ( dword_9A475 < (unsigned int)((unsigned __int64)(9092115387700LL * (unsigned __int8)dword_9A4CC) >> 32) >> 6 )
    {
      v0 = 3;
      goto LABEL_12;
    }
    if ( byte_9A49E != 100 || (unsigned int)dword_9A475 > 0xF1D )
      goto LABEL_7;
  }
  v0 = 4;
LABEL_12:
  v2 = ++dword_75F60;
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(
      s,
      0x1000u,
      "ret:%d [%d:%d]fan_error_num:%d fan_num %d fan_pwm %d fan_speed_value[0] %d fan_speed_value[1] %d",
      v0,
      dword_9A2BC == 1,
      dword_9A2BC == 2,
      v2,
      (unsigned __int8)byte_9A4A0,
      (unsigned __int8)dword_9A4CC,
      dword_9A471,
      dword_9A475);
    sub_385C8(7, s, 0);
    v2 = dword_75F60;
  }
  if ( v2 <= 10 )
    return 0;
  return v0;
}
