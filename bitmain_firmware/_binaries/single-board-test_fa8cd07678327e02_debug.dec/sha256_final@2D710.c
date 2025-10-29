void __cdecl sha256_final(sha256_ctx *ctx, unsigned __int8 *digest)
{
  int v2; // r3
  unsigned int pm_len; // [sp+8h] [bp+8h]
  unsigned int len_b; // [sp+Ch] [bp+Ch]
  unsigned int block_nb; // [sp+10h] [bp+10h]
  int i; // [sp+14h] [bp+14h]

  if ( (ctx->len & 0x3F) <= 0x37 )
    v2 = 1;
  else
    v2 = 2;
  block_nb = v2;
  len_b = 8 * (ctx->len + ctx->tot_len);
  pm_len = v2 << 6;
  memset(&ctx->block[ctx->len], 0, (v2 << 6) - ctx->len);
  ctx->block[ctx->len] = 0x80;
  ctx->block[pm_len - 1] = len_b;
  ctx->block[pm_len - 2] = BYTE1(len_b);
  ctx->block[pm_len - 3] = BYTE2(len_b);
  ctx->block[pm_len - 4] = HIBYTE(len_b);
  sha256_transf(ctx, ctx->block, block_nb);
  for ( i = 0; i <= 7; ++i )
  {
    digest[4 * i + 3] = ctx->h[i];
    digest[4 * i + 2] = BYTE1(ctx->h[i]);
    digest[4 * i + 1] = BYTE2(ctx->h[i]);
    digest[4 * i] = HIBYTE(ctx->h[i]);
  }
}
