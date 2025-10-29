void __cdecl sha256_transf(sha256_ctx *ctx, const unsigned __int8 *message, unsigned int block_nb)
{
  uint32_t wv[8]; // [sp+14h] [bp+14h]
  uint32_t w[64]; // [sp+34h] [bp+34h]
  uint32_t t2; // [sp+134h] [bp+134h]
  uint32_t t1; // [sp+138h] [bp+138h]
  const unsigned __int8 *sub_block; // [sp+13Ch] [bp+13Ch]
  int j; // [sp+140h] [bp+140h]
  int i; // [sp+144h] [bp+144h]

  for ( i = 0; i < (int)block_nb; ++i )
  {
    sub_block = &message[64 * i];
    for ( j = 0; j <= 15; ++j )
      w[j] = sub_block[4 * j + 3]
           | (sub_block[4 * j + 2] << 8)
           | (sub_block[4 * j + 1] << 16)
           | (sub_block[4 * j] << 24);
    for ( j = 16; j <= 63; ++j )
      w[j] = (__ROR4__(w[j - 2], 17) ^ __ROR4__(w[j - 2], 19) ^ (w[j - 2] >> 10))
           + w[j - 7]
           + ((w[j - 15] >> 3) ^ __ROR4__(w[j - 15], 7) ^ __ROR4__(w[j - 15], 18))
           + w[j - 16];
    for ( j = 0; j <= 7; ++j )
      wv[j] = ctx->h[j];
    for ( j = 0; j <= 63; ++j )
    {
      t1 = w[j]
         + wv[7]
         + (__ROR4__(wv[4], 25) ^ __ROR4__(wv[4], 6) ^ __ROR4__(wv[4], 11))
         + (wv[6] & ~wv[4] ^ wv[4] & wv[5])
         + sha256_k[j];
      t2 = (wv[2] & wv[1] ^ wv[0] & wv[1] ^ wv[2] & wv[0])
         + (__ROR4__(wv[0], 2) ^ __ROR4__(wv[0], 13) ^ __ROR4__(wv[0], 22));
      wv[7] = wv[6];
      wv[6] = wv[5];
      wv[5] = wv[4];
      wv[4] = wv[3] + t1;
      wv[3] = wv[2];
      wv[2] = wv[1];
      wv[1] = wv[0];
      wv[0] = t1 + t2;
    }
    for ( j = 0; j <= 7; ++j )
      ctx->h[j] += wv[j];
  }
}
