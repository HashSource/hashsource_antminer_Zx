unsigned __int8 __cdecl swap_bit(unsigned __int8 chr)
{
  int i; // [sp+8h] [bp+8h]
  unsigned __int8 ret; // [sp+Fh] [bp+Fh]

  ret = 0;
  for ( i = 0; i <= 7; ++i )
  {
    if ( (((int)chr >> i) & 1) != 0 )
      ret |= 1 << (7 - i);
  }
  return ret;
}
