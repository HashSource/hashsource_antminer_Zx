int __cdecl hex2bin(unsigned __int8 *p, const char *hexstr, size_t len)
{
  const char *v4; // r3
  unsigned __int8 *v5; // r3
  int nibble2; // [sp+10h] [bp+10h]
  int nibble1; // [sp+14h] [bp+14h]
  int ret; // [sp+1Ch] [bp+1Ch]

  ret = 0;
  while ( *hexstr && len )
  {
    if ( !hexstr[1] )
      return 0;
    nibble1 = hex2bin_tbl[*(unsigned __int8 *)hexstr];
    v4 = hexstr + 1;
    hexstr += 2;
    nibble2 = hex2bin_tbl[*(unsigned __int8 *)v4];
    if ( nibble1 < 0 || nibble2 < 0 )
      return 0;
    v5 = p++;
    *v5 = nibble2 | (16 * nibble1);
    --len;
  }
  if ( !len && !*hexstr )
    return 1;
  return ret;
}
