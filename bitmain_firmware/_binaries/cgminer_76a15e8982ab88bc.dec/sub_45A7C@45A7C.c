int sub_45A7C()
{
  int v0; // r0
  int result; // r0
  char v2; // r2
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  v0 = sub_45970(3);
  result = (unsigned __int8)sub_59AC8(256, v0);
  byte_9A4C7 = result;
  v2 = result;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s:addrInterval = %d", "calculate_address_interval", (unsigned __int8)result);
    sub_385C8(5, s, 0);
    v2 = byte_9A4C7;
  }
  byte_75F71 = 2 * v2;
  byte_75F70[0] = 0;
  return result;
}
