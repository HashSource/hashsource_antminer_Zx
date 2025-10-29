// Alternative name is 'sha2_update.part.0'
void __fastcall sha2_update_0(sha2_context *ctx, const unsigned __int8 *input, int ilen)
{
  signed int v3; // r5
  uint32_t v4; // r3
  const unsigned __int8 *v6; // r4
  bool v7; // cf
  uint32_t v8; // r2
  uint32_t v9; // r8
  signed int v10; // r7
  _BOOL4 v11; // r3
  unsigned int v12; // r5
  const unsigned __int8 *v13; // r7
  const unsigned __int8 *v14; // r1
  unsigned __int8 *buffer; // r9

  v3 = ilen;
  v4 = ctx->total[0];
  v6 = input;
  v7 = __CFADD__(ctx->total[0], ilen);
  v8 = ctx->total[0] + ilen;
  v9 = ctx->total[0] & 0x3F;
  if ( v7 )
    v4 = ctx->total[1];
  v10 = 64 - v9;
  ctx->total[0] = v8;
  if ( v7 )
    ctx->total[1] = v4 + 1;
  v11 = v10 <= v3;
  if ( !v9 )
    v11 = 0;
  if ( v11 )
  {
    buffer = ctx->buffer;
    v3 -= v10;
    memcpy(&ctx->buffer[v9], input, 64 - v9);
    v6 += v10;
    v9 = 0;
    sha2_process(ctx, buffer);
  }
  if ( v3 > 63 )
  {
    v12 = v3 - 64;
    v13 = &v6[64 * (v12 >> 6) + 64];
    do
    {
      v14 = v6;
      v6 += 64;
      sha2_process(ctx, v14);
    }
    while ( v6 != v13 );
    v3 = v12 - (v12 >> 6 << 6);
  }
  if ( v3 > 0 )
    sub_12058(&ctx->buffer[v9], v6, v3);
}
