void __cdecl sha256(const unsigned __int8 *message, unsigned int len, unsigned __int8 *digest)
{
  sha256_ctx ctx; // [sp+10h] [bp+10h] BYREF

  sha256_init(&ctx);
  sha256_update(&ctx, message, len);
  sha256_final(&ctx, digest);
}
