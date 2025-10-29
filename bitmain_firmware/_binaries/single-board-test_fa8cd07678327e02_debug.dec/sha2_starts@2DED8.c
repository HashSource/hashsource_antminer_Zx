void __cdecl sha2_starts(sha2_context *ctx)
{
  ctx->total[0] = 0;
  ctx->total[1] = 0;
  ctx->state[0] = 1779033703;
  ctx->state[1] = -1150833019;
  ctx->state[2] = 1013904242;
  ctx->state[3] = -1521486534;
  ctx->state[4] = 1359893119;
  ctx->state[5] = -1694144372;
  ctx->state[6] = 528734635;
  ctx->state[7] = 1541459225;
}
