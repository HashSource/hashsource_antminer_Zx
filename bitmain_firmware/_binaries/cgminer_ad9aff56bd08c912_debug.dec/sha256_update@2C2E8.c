void __fastcall sha256_update(sha256_ctx *ctx, const unsigned __int8 *message, unsigned int len)
{
  unsigned int v4; // r0
  size_t v7; // r6
  unsigned __int8 *v8; // r0
  unsigned int v9; // r3
  unsigned int v10; // r5
  const unsigned __int8 *v11; // r6
  unsigned int tot_len; // r3

  v4 = ctx->len;
  v7 = 64 - v4;
  v8 = &ctx->block[v4];
  if ( v7 >= len )
    v7 = len;
  memcpy(v8, message, v7);
  v9 = ctx->len + len;
  if ( v9 > 0x3F )
  {
    v10 = len - v7;
    v11 = &message[v7];
    sha256_transf(ctx, ctx->block, 1u);
    sha256_transf(ctx, v11, v10 >> 6);
    memcpy(ctx->block, &v11[v10 & 0xFFFFFFC0], v10 & 0x3F);
    tot_len = ctx->tot_len;
    ctx->len = v10 & 0x3F;
    ctx->tot_len = tot_len + (((v10 >> 6) + 1) << 6);
  }
  else
  {
    ctx->len = v9;
  }
}
