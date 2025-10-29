bool __fastcall HasCollision(const uint8_t *a, const uint8_t *b, int l)
{
  const uint8_t *v3; // r2
  int v4; // r4
  int v5; // t1
  int v6; // t1

  if ( l <= 0 )
    return 1;
  if ( *a != *b )
    return 0;
  v3 = &a[l - 1];
  while ( a != v3 )
  {
    v5 = *++a;
    v4 = v5;
    v6 = *++b;
    if ( v4 != v6 )
      return 0;
  }
  return 1;
}
