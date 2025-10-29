unsigned int *__fastcall sub_4C914(unsigned int *result, unsigned int *a2, int a3)
{
  signed int v3; // r7
  unsigned int *v4; // r6
  unsigned int *v5; // r8
  unsigned int v6; // r10
  unsigned int v7; // r3
  int v8; // r10
  int v9; // r4
  _BOOL4 v10; // r3
  int v11; // r5
  unsigned int *v12; // r4
  unsigned int *v13; // r1
  unsigned int v14; // r7
  int v15; // r2

  v3 = a3;
  v4 = result;
  v5 = a2;
  if ( a3 > 0 )
  {
    v6 = *result;
    v7 = a3 + *result;
    *result = v7;
    v8 = v6 & 0x3F;
    v9 = 64 - v8;
    if ( a3 > v7 )
      ++result[1];
    v10 = a3 >= v9;
    if ( !v8 )
      v10 = 0;
    if ( v10 )
    {
      v3 = a3 - v9;
      memcpy((char *)result + v8 + 40, a2, 64 - v8);
      v5 = (unsigned int *)((char *)v5 + v9);
      result = (unsigned int *)sub_4A218(v4, v4 + 10);
      v8 = 0;
    }
    if ( v3 > 63 )
    {
      v11 = v3;
      v12 = v5;
      do
      {
        v13 = v12;
        v11 -= 64;
        v12 += 16;
        result = (unsigned int *)sub_4A218(v4, v13);
      }
      while ( v11 > 63 );
      v14 = v3 - 64;
      v15 = (v14 >> 6) + 1;
      v3 = v14 - (v14 >> 6 << 6);
      v5 += 16 * v15;
    }
    if ( v3 > 0 )
      return (unsigned int *)memcpy((char *)v4 + v8 + 40, v5, v3);
  }
  return result;
}
