void __cdecl sha2_update(sha2_context *ctx, const unsigned __int8 *input, int ilen)
{
  signed int ilena; // [sp+4h] [bp+4h]
  const unsigned __int8 *inputa; // [sp+8h] [bp+8h]
  signed int fill; // [sp+10h] [bp+10h]
  uint32_t left; // [sp+14h] [bp+14h]

  inputa = input;
  ilena = ilen;
  if ( ilen > 0 )
  {
    left = ctx->total[0] & 0x3F;
    fill = 64 - left;
    ctx->total[0] += ilen;
    ctx->total[0] = ctx->total[0];
    if ( ctx->total[0] < ilen )
      ++ctx->total[1];
    if ( left && ilen >= fill )
    {
      memcpy(&ctx->buffer[left], input, fill);
      sha2_process(ctx, ctx->buffer);
      inputa += fill;
      ilena -= fill;
      left = 0;
    }
    while ( ilena > 63 )
    {
      sha2_process(ctx, inputa);
      inputa += 64;
      ilena -= 64;
    }
    if ( ilena > 0 )
      memcpy(&ctx->buffer[left], inputa, ilena);
  }
}
