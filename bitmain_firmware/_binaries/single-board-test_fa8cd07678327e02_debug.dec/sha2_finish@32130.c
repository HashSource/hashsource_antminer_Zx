// local variable allocation has failed, the output may be wrong!
void __cdecl sha2_finish(sha2_context *ctx, unsigned __int8 *output)
{
  uint32_t v2; // r3
  unsigned __int8 msglen[8]; // [sp+8h] [bp+8h] BYREF
  uint32_t padn; // [sp+10h] [bp+10h]
  uint32_t last; // [sp+14h] [bp+14h]
  __int64 low; // [sp+18h] [bp+18h] OVERLAPPED

  low = 8LL * *(_QWORD *)ctx->total;
  msglen[0] = HIBYTE(low);
  msglen[1] = BYTE6(low);
  msglen[2] = BYTE5(low);
  msglen[3] = BYTE4(low);
  msglen[4] = BYTE3(low);
  msglen[5] = BYTE2(low);
  msglen[6] = BYTE1(low);
  msglen[7] = low;
  last = ctx->total[0] & 0x3F;
  if ( last > 0x37 )
    v2 = 120 - last;
  else
    v2 = 56 - last;
  padn = v2;
  sha2_update(ctx, sha2_padding, v2);
  sha2_update(ctx, msglen, 8);
  *output = HIBYTE(ctx->state[0]);
  output[1] = BYTE2(ctx->state[0]);
  output[2] = BYTE1(ctx->state[0]);
  output[3] = ctx->state[0];
  output[4] = HIBYTE(ctx->state[1]);
  output[5] = BYTE2(ctx->state[1]);
  output[6] = BYTE1(ctx->state[1]);
  output[7] = ctx->state[1];
  output[8] = HIBYTE(ctx->state[2]);
  output[9] = BYTE2(ctx->state[2]);
  output[10] = BYTE1(ctx->state[2]);
  output[11] = ctx->state[2];
  output[12] = HIBYTE(ctx->state[3]);
  output[13] = BYTE2(ctx->state[3]);
  output[14] = BYTE1(ctx->state[3]);
  output[15] = ctx->state[3];
  output[16] = HIBYTE(ctx->state[4]);
  output[17] = BYTE2(ctx->state[4]);
  output[18] = BYTE1(ctx->state[4]);
  output[19] = ctx->state[4];
  output[20] = HIBYTE(ctx->state[5]);
  output[21] = BYTE2(ctx->state[5]);
  output[22] = BYTE1(ctx->state[5]);
  output[23] = ctx->state[5];
  output[24] = HIBYTE(ctx->state[6]);
  output[25] = BYTE2(ctx->state[6]);
  output[26] = BYTE1(ctx->state[6]);
  output[27] = ctx->state[6];
  output[28] = HIBYTE(ctx->state[7]);
  output[29] = BYTE2(ctx->state[7]);
  output[30] = BYTE1(ctx->state[7]);
  output[31] = ctx->state[7];
}
