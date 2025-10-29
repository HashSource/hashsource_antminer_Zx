int sub_467B0()
{
  int v0; // r0
  unsigned __int8 v1; // r0
  int v2; // r2
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  v0 = sub_466A4(3);
  v1 = sub_5C710(256, v0);
  byte_9D6F3 = v1;
  v2 = v1;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s:addrInterval = %d", "calculate_address_interval", v1);
    sub_38730(5, s, 0);
    v2 = (unsigned __int8)byte_9D6F3;
  }
  byte_79131 = v2;
  byte_79132 = 2 * v2;
  byte_79130[0] = 0;
  return 2 * v2;
}
