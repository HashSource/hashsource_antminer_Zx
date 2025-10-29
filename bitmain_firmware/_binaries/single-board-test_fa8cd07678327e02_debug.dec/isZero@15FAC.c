int __cdecl isZero(const uint8_t *hash, size_t len)
{
  size_t i; // [sp+Ch] [bp+Ch]

  for ( i = 0; i < len; ++i )
  {
    if ( hash[i] )
      return 0;
  }
  return 1;
}
