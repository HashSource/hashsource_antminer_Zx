int sub_463C8()
{
  int v0; // r6
  int i; // r4
  int v2; // t1
  int v3; // r5
  int v4; // r1
  int result; // r0

  v0 = 644283;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      v3 = 0;
      do
      {
        v4 = v3;
        v3 = (unsigned __int8)(v3 + 1);
        result = sub_4633C(i, v4, 76, 9u, 4u);
      }
      while ( v3 != 3 );
    }
  }
  return result;
}
