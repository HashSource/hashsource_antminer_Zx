void __cdecl expandArray(
        const unsigned __int8 *in,
        const size_t in_len,
        unsigned __int8 *out,
        const size_t out_len,
        const size_t bit_len,
        const size_t byte_pad)
{
  size_t out_width; // [sp+14h] [bp+14h]
  size_t x_0; // [sp+18h] [bp+18h]
  size_t x; // [sp+1Ch] [bp+1Ch]
  size_t i; // [sp+20h] [bp+20h]
  size_t j; // [sp+24h] [bp+24h]
  uint32_t acc_value; // [sp+28h] [bp+28h]
  size_t acc_bits; // [sp+2Ch] [bp+2Ch]

  if ( bit_len <= 7 )
    _assert_fail("bit_len >= 8", "bm174x/equihash-verify.c", 0x3Eu, "expandArray");
  if ( bit_len + 7 > 0x20 )
    _assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len", "bm174x/equihash-verify.c", 0x3Fu, "expandArray");
  out_width = byte_pad + ((bit_len + 7) >> 3);
  if ( 8 * in_len * out_width / bit_len != out_len )
    _assert_fail("out_len == 8 * out_width * in_len / bit_len", "bm174x/equihash-verify.c", 0x42u, "expandArray");
  acc_bits = 0;
  acc_value = 0;
  j = 0;
  for ( i = 0; i < in_len; ++i )
  {
    acc_value = (acc_value << 8) | in[i];
    acc_bits += 8;
    if ( acc_bits >= bit_len )
    {
      acc_bits -= bit_len;
      for ( x = 0; x < byte_pad; ++x )
        out[x + j] = 0;
      for ( x_0 = byte_pad; x_0 < out_width; ++x_0 )
        out[x_0 + j] = ((unsigned int)((1 << bit_len) - 1) >> (8 * (out_width - x_0 - 1)))
                     & (acc_value >> (acc_bits + 8 * (out_width - x_0 - 1)));
      j += out_width;
    }
  }
}
