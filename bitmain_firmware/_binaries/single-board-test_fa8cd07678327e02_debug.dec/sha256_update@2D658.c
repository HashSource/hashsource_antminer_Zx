void __cdecl sha256_update(sha256_ctx *ctx, const unsigned __int8 *message, unsigned int len)
{
  size_t v3; // r3
  const unsigned __int8 *shifted_message; // [sp+14h] [bp+14h]
  unsigned int block_nb; // [sp+18h] [bp+18h]
  unsigned int rem_len; // [sp+20h] [bp+20h]
  size_t rem_lena; // [sp+20h] [bp+20h]

  v3 = len;
  if ( len >= 64 - ctx->len )
    v3 = 64 - ctx->len;
  rem_len = v3;
  memcpy(&ctx->block[ctx->len], message, v3);
  if ( len + ctx->len > 0x3F )
  {
    block_nb = (len - rem_len) >> 6;
    shifted_message = &message[rem_len];
    sha256_transf(ctx, ctx->block, 1u);
    sha256_transf(ctx, &message[rem_len], block_nb);
    rem_lena = (len - rem_len) & 0x3F;
    memcpy(ctx->block, &shifted_message[64 * block_nb], rem_lena);
    ctx->len = rem_lena;
    ctx->tot_len += (block_nb + 1) << 6;
  }
  else
  {
    ctx->len += len;
  }
}
