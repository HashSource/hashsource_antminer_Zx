void __cdecl compressArray(
        const unsigned __int8 *in,
        const size_t in_len,
        unsigned __int8 *out,
        const size_t out_len,
        const size_t bit_len,
        const size_t byte_pad)
{
  size_t in_width; // [sp+18h] [bp+18h]
  size_t x; // [sp+1Ch] [bp+1Ch]
  size_t i; // [sp+20h] [bp+20h]
  size_t j; // [sp+24h] [bp+24h]
  uint32_t acc_value; // [sp+28h] [bp+28h]
  size_t acc_bits; // [sp+2Ch] [bp+2Ch]

  if ( bit_len <= 7 )
    _assert_fail("bit_len >= 8", "bm174x/equihash-verify.c", 0x14u, "compressArray");
  if ( bit_len + 7 > 0x20 )
    _assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len", "bm174x/equihash-verify.c", 0x15u, "compressArray");
  in_width = byte_pad + ((bit_len + 7) >> 3);
  if ( in_len * bit_len / (8 * in_width) != out_len )
    _assert_fail("out_len == bit_len * in_len / (8 * in_width)", "bm174x/equihash-verify.c", 0x18u, "compressArray");
  acc_bits = 0;
  acc_value = 0;
  j = 0;
  for ( i = 0; i < out_len; ++i )
  {
    if ( acc_bits <= 7 )
    {
      acc_value <<= bit_len;
      for ( x = byte_pad; x < in_width; ++x )
        acc_value |= (((unsigned int)((1 << bit_len) - 1) >> (8 * (in_width - x - 1))) & in[x + j]) << (8 * (in_width - x - 1));
      j += in_width;
      acc_bits += bit_len;
    }
    acc_bits -= 8;
    out[i] = acc_value >> acc_bits;
  }
}
