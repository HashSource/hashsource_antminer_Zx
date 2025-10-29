void __fastcall sort_pair(uint32_t *a, uint32_t len)
{
  uint32_t *v2; // r2
  uint32_t v3; // r3
  uint32_t *v4; // r7
  uint32_t *v5; // r6
  uint32_t v6; // r5
  uint32_t v7; // t1
  uint32_t v8; // r4
  uint32_t v9; // t1
  bool v10; // cf
  uint32_t *v11; // r0
  uint32_t *v12; // r2

  v2 = &a[len];
  if ( len )
  {
    v3 = 0;
    v4 = a - 1;
    v5 = v2 - 1;
    while ( 1 )
    {
      v7 = v4[1];
      ++v4;
      v6 = v7;
      v9 = v5[1];
      ++v5;
      v8 = v9;
      v10 = v6 >= v9;
      if ( v6 > v9 )
        break;
      ++v3;
      if ( !v10 || len == v3 )
        return;
    }
    v11 = &a[v3];
    v12 = &v2[v3];
    while ( 1 )
    {
      ++v3;
      *v11++ = v8;
      *v12++ = v6;
      if ( len <= v3 )
        break;
      v8 = *v12;
      v6 = *v11;
    }
  }
}
