void __fastcall sha256_final(sha256_ctx *ctx, unsigned __int8 *digest)
{
  unsigned int len; // r3
  unsigned __int8 *block; // r6
  bool v6; // cf
  int v7; // r2
  unsigned int v8; // r7
  size_t v9; // r2
  unsigned __int8 *v10; // r0
  int v11; // r3
  int v12; // r8
  int v13; // r9
  int v14; // r10
  unsigned int v15; // r11
  int v16; // r7
  uint32_t *h; // r3
  sha256_ctx *v18; // r5
  int v19; // t1
  int v20; // [sp+4h] [bp-8h]

  len = ctx->len;
  block = ctx->block;
  v6 = (len & 0x3F) >= 0x38;
  if ( (len & 0x3F) >= 0x38 )
    v7 = 128;
  else
    v7 = 64;
  v8 = ctx->tot_len + len;
  v9 = v7 - len;
  v10 = &block[len];
  if ( (len & 0x3F) >= 0x38 )
    v11 = 124;
  else
    v11 = 60;
  if ( v6 )
    v12 = 125;
  else
    v12 = 61;
  if ( v6 )
    v13 = 126;
  else
    v13 = 62;
  if ( v6 )
    v14 = 127;
  else
    v14 = 63;
  if ( v6 )
    v15 = 2;
  else
    v15 = 1;
  v20 = v11;
  memset(v10, 0, v9);
  v16 = 8 * v8;
  ctx->block[ctx->len] = 0x80;
  block[v14] = v16;
  block[v13] = BYTE1(v16);
  block[v12] = BYTE2(v16);
  block[v20] = HIBYTE(v16);
  sha256_transf(ctx, block, v15);
  h = ctx->h;
  v18 = ctx + 1;
  do
  {
    digest[3] = *h;
    v19 = *h++;
    digest[2] = BYTE1(v19);
    digest[1] = *((_WORD *)h - 1);
    *digest = *((_BYTE *)h - 1);
    digest += 4;
  }
  while ( v18 != (sha256_ctx *)h );
}
