bool __fastcall DistinctIndices(const uint8_t *a, const uint8_t *b, size_t hashLen, uint32_t indicesLen)
{
  const uint8_t *v4; // r0
  const uint8_t *v5; // r1
  unsigned __int8 *v6; // r6
  uint32_t i; // r4
  int v8; // r2
  unsigned __int8 *v9; // r5

  if ( !indicesLen )
    return 1;
  v4 = &a[hashLen];
  v5 = &b[hashLen];
  v6 = (unsigned __int8 *)v4;
  do
  {
    for ( i = 0; i < indicesLen; i += 4 )
    {
      v8 = v5[i];
      v9 = (unsigned __int8 *)&v5[i];
      if ( *v6 == v8 && v6[1] == v9[1] && v6[2] == v9[2] && v6[3] == v9[3] )
        return 0;
    }
    v6 += 4;
  }
  while ( v6 - v4 < indicesLen );
  return 1;
}
