void __fastcall expandArray(
        const unsigned __int8 *in,
        const size_t in_len,
        unsigned __int8 *out,
        const size_t out_len,
        const size_t bit_len,
        const size_t byte_pad)
{
  size_t v7; // r8
  const unsigned __int8 *v8; // r0
  int v9; // lr
  unsigned int v10; // r6
  size_t v11; // r5
  int v12; // t1
  unsigned __int8 *v13; // r3
  size_t v14; // r1
  unsigned __int8 *v15; // r4
  unsigned int v16; // r3
  unsigned int v17; // r2
  const unsigned __int8 *v18; // [sp+4h] [bp-18h]

  if ( bit_len <= 7 )
    _assert_fail("bit_len >= 8", "sort-verify.c", 0x40u, "expandArray");
  if ( bit_len + 7 > 0x20 )
    _assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len", "sort-verify.c", 0x41u, "expandArray");
  v7 = byte_pad + ((bit_len + 7) >> 3);
  if ( v7 * 8 * in_len / bit_len != out_len )
    _assert_fail("out_len == 8 * out_width * in_len / bit_len", "sort-verify.c", 0x44u, "expandArray");
  if ( in_len )
  {
    v8 = in - 1;
    v18 = &in[in_len - 1];
    v9 = 0;
    v10 = 0;
    v11 = 0;
    do
    {
      while ( 1 )
      {
        v12 = *++v8;
        v11 += 8;
        v10 = v12 | (v10 << 8);
        if ( bit_len <= v11 )
          break;
        if ( v8 == v18 )
          return;
      }
      v11 -= bit_len;
      if ( byte_pad )
      {
        v13 = &out[v9];
        do
          *v13++ = 0;
        while ( &out[byte_pad + v9] != v13 );
      }
      if ( byte_pad < v7 )
      {
        v14 = v11 + 8 * (((bit_len + 7) >> 3) + 0x1FFFFFFF);
        v15 = &out[byte_pad + v9];
        do
        {
          v16 = v10 >> v14;
          v17 = (unsigned int)((1 << bit_len) - 1) >> (v14 - v11);
          v14 -= 8;
          *v15++ = v16 & v17;
        }
        while ( &out[v7 + v9] != v15 );
      }
      v9 += v7;
    }
    while ( v8 != v18 );
  }
}
