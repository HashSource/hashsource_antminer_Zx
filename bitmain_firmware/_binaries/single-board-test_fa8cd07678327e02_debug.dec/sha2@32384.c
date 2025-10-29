void __cdecl sha2(const unsigned __int8 *input, int ilen, unsigned __int8 *output)
{
  sha2_context ctx; // [sp+10h] [bp+10h] BYREF

  sha2_starts(&ctx);
  sha2_update(&ctx, input, ilen);
  sha2_finish(&ctx, output);
  memset(&ctx, 0, sizeof(ctx));
}
