unsigned int *__fastcall sub_4E134(unsigned int *result, int a2)
{
  unsigned int *v2; // r3
  int v3; // r2
  int v4; // r5
  unsigned int v5; // r12
  unsigned int v6; // r4

  v2 = &result[a2];
  if ( a2 )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      v5 = *result;
      v6 = *v2;
      if ( v4 || v5 > v6 )
      {
        *result = v6;
        v4 = 1;
        *v2 = v5;
      }
      else if ( v5 < v6 )
      {
        return result;
      }
      ++v3;
      ++result;
      ++v2;
    }
    while ( v3 != a2 );
  }
  return result;
}
