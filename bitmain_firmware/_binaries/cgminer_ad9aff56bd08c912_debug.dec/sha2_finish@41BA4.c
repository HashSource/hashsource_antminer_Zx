void __fastcall sha2_finish(sha2_context *ctx, unsigned __int8 *output)
{
  uint32_t v4; // r2
  uint32_t v5; // r3
  unsigned int v6; // r6
  uint32_t v7; // r0
  uint32_t v8; // r3
  unsigned int v9; // r1
  int v10; // r2
  unsigned __int8 msglen[8]; // [sp+0h] [bp-8h] BYREF

  v4 = ctx->total[0] & 0x3F;
  v9 = *(_QWORD *)ctx->total >> 29;
  v5 = 8 * ctx->total[0];
  msglen[7] = 8 * LOBYTE(ctx->total[0]);
  msglen[4] = HIBYTE(v5);
  v6 = HIBYTE(v9);
  msglen[3] = v9;
  msglen[1] = BYTE2(v9);
  v7 = HIWORD(v5);
  v8 = v5 >> 8;
  msglen[2] = BYTE1(v9);
  LOWORD(v9) = -22192;
  msglen[5] = v7;
  if ( v4 > 0x37 )
    v10 = 120 - v4;
  else
    v10 = 56 - v4;
  HIWORD(v9) = (unsigned int)"Asic Response.Chain Id:[%d]" >> 16;
  msglen[6] = v8;
  msglen[0] = v6;
  sha2_update_0(ctx, (const unsigned __int8 *)v9, v10);
  sha2_update_0(ctx, msglen, 8);
  *output = HIBYTE(ctx->state[0]);
  output[1] = HIWORD(ctx->state[0]);
  output[2] = BYTE1(ctx->state[0]);
  output[3] = ctx->state[0];
  output[4] = HIBYTE(ctx->state[1]);
  output[5] = HIWORD(ctx->state[1]);
  output[6] = BYTE1(ctx->state[1]);
  output[7] = ctx->state[1];
  output[8] = HIBYTE(ctx->state[2]);
  output[9] = HIWORD(ctx->state[2]);
  output[10] = BYTE1(ctx->state[2]);
  output[11] = ctx->state[2];
  output[12] = HIBYTE(ctx->state[3]);
  output[13] = HIWORD(ctx->state[3]);
  output[14] = BYTE1(ctx->state[3]);
  output[15] = ctx->state[3];
  output[16] = HIBYTE(ctx->state[4]);
  output[17] = HIWORD(ctx->state[4]);
  output[18] = BYTE1(ctx->state[4]);
  output[19] = ctx->state[4];
  output[20] = HIBYTE(ctx->state[5]);
  output[21] = HIWORD(ctx->state[5]);
  output[22] = BYTE1(ctx->state[5]);
  output[23] = ctx->state[5];
  output[24] = HIBYTE(ctx->state[6]);
  output[25] = HIWORD(ctx->state[6]);
  output[26] = BYTE1(ctx->state[6]);
  output[27] = ctx->state[6];
  output[28] = HIBYTE(ctx->state[7]);
  output[29] = HIWORD(ctx->state[7]);
  output[30] = BYTE1(ctx->state[7]);
  output[31] = ctx->state[7];
}
