void __cdecl generateHash(blake2b_state *S, const uint32_t g, uint8_t *hash, const size_t hashLen)
{
  uint8_t hashLena; // [sp+0h] [bp+0h]
  blake2b_state digest; // [sp+10h] [bp+10h] BYREF
  uint32_t le_g[2]; // [sp+17Ch] [bp+17Ch] BYREF

  hashLena = hashLen;
  le_g[0] = g;
  memcpy(&digest, S, sizeof(digest));
  blake2b_update(&digest, (const uint8_t *)le_g, 4u);
  blake2b_final(&digest, hash, hashLena);
}
