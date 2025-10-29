void __fastcall sha256_init(sha256_ctx *ctx)
{
  uint32_t *v1; // r2
  sha256_ctx *h; // r3
  unsigned int v3; // t1

  v1 = &sha256_k[63];
  h = (sha256_ctx *)ctx->h;
  do
  {
    v3 = v1[1];
    ++v1;
    h->tot_len = v3;
    h = (sha256_ctx *)((char *)h + 4);
  }
  while ( h != &ctx[1] );
  ctx->tot_len = 0;
  ctx->len = 0;
}
