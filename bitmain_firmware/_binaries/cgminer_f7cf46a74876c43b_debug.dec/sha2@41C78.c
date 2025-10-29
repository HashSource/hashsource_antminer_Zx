void __fastcall sha2(const unsigned __int8 *input, int ilen, unsigned __int8 *output)
{
  sha2_context ctx; // [sp+0h] [bp-E8h] BYREF

  ctx.state[0] = 1779033703;
  ctx.state[3] = -1521486534;
  ctx.state[4] = 1359893119;
  ctx.state[2] = 1013904242;
  ctx.state[6] = 528734635;
  ctx.state[7] = 1541459225;
  ctx.state[5] = -1694144372;
  ctx.state[1] = -1150833019;
  ctx.total[0] = 0;
  ctx.total[1] = 0;
  if ( ilen > 0 )
    sha2_update_0(&ctx, input, ilen);
  sha2_finish(&ctx, output);
}
