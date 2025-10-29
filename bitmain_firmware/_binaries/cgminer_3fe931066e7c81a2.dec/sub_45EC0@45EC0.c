int sub_45EC0()
{
  float v0; // s0
  int result; // r0
  _BOOL4 v2; // r3
  int v3; // r3
  int v4; // r6
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  result = dword_9D6D6;
  dword_79128 = dword_9D6D6;
  if ( byte_9D6F7 && (unsigned __int8)dword_9D6F8 <= 0x64u )
    return sub_45D88((unsigned __int8)dword_9D6F8);
  v2 = dword_9D6D6 > 62;
  if ( !dword_9D6D6 )
    v2 = 1;
  if ( v2 )
  {
    result = sub_45D88(100);
    LOBYTE(dword_9D6F8) = 100;
  }
  else if ( dword_9D6D6 <= 35 )
  {
    result = sub_45D88(40);
    LOBYTE(dword_9D6F8) = 40;
  }
  else if ( (unsigned int)(dword_9D6D6 - dword_7912C + 1) > 2 )
  {
    sub_45DEC();
    v3 = (int)v0 & ~((int)v0 >> 31);
    v4 = (unsigned __int8)v3;
    LOBYTE(dword_9D6F8) = (int)v0 & ~((int)v0 >> 31);
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "%s: Set PWM percent : %d", "set_PWM_according_to_temperature", v3);
      sub_38730(7, s, 0);
    }
    result = sub_45D88(v4);
    dword_7912C = dword_79128;
  }
  return result;
}
