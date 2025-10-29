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
  const char *v18; // r3
  const char *v19; // r1
  const char *v20; // r0
  const char *v21; // r3
  const char *v22; // r1
  const char *v23; // r0
  const char *v24; // r3
  const char *v25; // r1
  const char *v26; // r0
  const unsigned __int8 *v27; // [sp+4h] [bp-18h]

  if ( bit_len <= 7 )
  {
    LOWORD(v18) = -22128;
    LOWORD(v19) = -22116;
    LOWORD(v20) = -22100;
    HIWORD(v18) = (unsigned int)&sha2_padding[16] >> 16;
    HIWORD(v19) = (unsigned int)&sha2_padding[28] >> 16;
    HIWORD(v20) = (unsigned int)&sha2_padding[44] >> 16;
    _assert_fail(v20, v19, 0x40u, v18);
  }
  if ( bit_len + 7 > 0x20 )
  {
    LOWORD(v24) = -22128;
    LOWORD(v25) = -22116;
    LOWORD(v26) = -22084;
    HIWORD(v24) = (unsigned int)&sha2_padding[16] >> 16;
    HIWORD(v25) = (unsigned int)&sha2_padding[28] >> 16;
    HIWORD(v26) = (unsigned int)&sha2_padding[60] >> 16;
    _assert_fail(v26, v25, 0x41u, v24);
  }
  v7 = byte_pad + ((bit_len + 7) >> 3);
  if ( v7 * 8 * in_len / bit_len != out_len )
  {
    LOWORD(v21) = -22128;
    LOWORD(v22) = -22116;
    LOWORD(v23) = -22048;
    HIWORD(v21) = (unsigned int)&sha2_padding[16] >> 16;
    HIWORD(v22) = (unsigned int)&sha2_padding[28] >> 16;
    HIWORD(v23) = (unsigned int)"len >= 8" >> 16;
    _assert_fail(v23, v22, 0x44u, v21);
  }
  if ( in_len )
  {
    v8 = in - 1;
    v27 = &in[in_len - 1];
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
        if ( v8 == v27 )
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
    while ( v8 != v27 );
  }
}
