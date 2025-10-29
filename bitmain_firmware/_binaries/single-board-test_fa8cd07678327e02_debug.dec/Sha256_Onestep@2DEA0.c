void __cdecl Sha256_Onestep(const uint8_t *data, size_t size, uint8_t *digest)
{
  CSha256 p; // [sp+10h] [bp+10h] BYREF

  Sha256_Init(&p);
  Sha256_Update(&p, data, size);
  Sha256_Final(&p, digest);
}
