int __fastcall utf8_check_first(char byte)
{
  if ( (byte & 0x80) == 0 )
    return 1;
  if ( (byte ^ 0x80u) <= 0x41 )
    return 0;
  if ( (unsigned __int8)(byte + 62) <= 0x1Du )
    return 2;
  if ( (unsigned __int8)(byte + 32) <= 0xFu )
    return 3;
  if ( (unsigned __int8)(byte + 16) <= 4u )
    return 4;
  return 0;
}
