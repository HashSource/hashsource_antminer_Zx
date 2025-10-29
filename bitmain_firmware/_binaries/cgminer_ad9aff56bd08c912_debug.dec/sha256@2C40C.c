void __fastcall sha256(const unsigned __int8 *message, unsigned int len, unsigned __int8 *digest)
{
  uint32_t *v3; // r3
  uint32_t *h; // r2
  uint32_t v6; // t1
  sha256_ctx ctx; // [sp+0h] [bp-A8h] BYREF

  v3 = &sha256_k[63];
  h = ctx.h;
  do
  {
    v6 = v3[1];
    ++v3;
    *h++ = v6;
  }
  while ( v3 != &sha256_h0[7] );
  ctx.tot_len = 0;
  ctx.len = 0;
  sha256_update(&ctx, message, len);
  sha256_final(&ctx, digest);
}
