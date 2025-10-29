void __cdecl sha256_init(sha256_ctx *ctx)
{
  int i; // [sp+Ch] [bp+Ch]

  for ( i = 0; i <= 7; ++i )
    ctx->h[i] = sha256_h0[i];
  ctx->len = 0;
  ctx->tot_len = 0;
}
