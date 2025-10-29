bool __fastcall IsZero(const uint8_t *a, size_t len)
{
  const uint8_t *v2; // r1

  if ( !len )
    return 1;
  if ( !*a )
  {
    v2 = &a[len - 1];
    while ( a != v2 )
    {
      if ( *++a )
        return 0;
    }
    return 1;
  }
  return 0;
}
