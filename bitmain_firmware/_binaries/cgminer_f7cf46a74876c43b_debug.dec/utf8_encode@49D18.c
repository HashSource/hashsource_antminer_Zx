int __fastcall utf8_encode(int32_t codepoint, char *buffer, int *size)
{
  char v3; // r3
  char v5; // r3
  unsigned int v6; // r4
  char v7; // r3

  if ( codepoint < 0 )
    return -1;
  if ( codepoint <= 127 )
  {
    *buffer = codepoint;
    *size = 1;
    return 0;
  }
  else if ( codepoint < 2048 )
  {
    v5 = (codepoint & 0x3F) + 0x80;
    *buffer = (codepoint >> 6) - 64;
    buffer[1] = v5;
    *size = 2;
    return 0;
  }
  else if ( codepoint < 0x10000 )
  {
    v6 = ((unsigned int)codepoint >> 6) & 0x3F;
    v7 = (codepoint & 0x3F) + 0x80;
    *buffer = (codepoint >> 12) - 32;
    buffer[1] = v6 + 0x80;
    buffer[2] = v7;
    *size = 3;
    return 0;
  }
  else if ( codepoint >= 1114112 )
  {
    return -1;
  }
  else
  {
    v3 = (codepoint & 0x3F) + 0x80;
    *buffer = (codepoint >> 18) - 16;
    buffer[1] = (((unsigned int)codepoint >> 12) & 0x3F) + 0x80;
    buffer[2] = (((unsigned int)codepoint >> 6) & 0x3F) + 0x80;
    buffer[3] = v3;
    *size = 4;
    return 0;
  }
}
