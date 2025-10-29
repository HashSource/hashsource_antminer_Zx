void __fastcall generateHash(blake2b_state *S, const uint32_t g, uint8_t *hash, const size_t hashLen)
{
  uint8_t v5; // r5
  uint32_t le_g; // [sp+4h] [bp-170h] BYREF
  blake2b_state digest; // [sp+8h] [bp-16Ch] BYREF

  le_g = g;
  v5 = hashLen;
  memcpy(&digest, S, sizeof(digest));
  blake2b_update(&digest, (const uint8_t *)&le_g, 4u);
  blake2b_final(&digest, hash, v5);
}
