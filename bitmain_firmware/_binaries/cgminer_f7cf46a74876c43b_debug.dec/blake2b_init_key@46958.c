int __fastcall blake2b_init_key(blake2b_state *S, const uint8_t outlen, const void *key, const uint8_t keylen)
{
  size_t v5; // r5
  blake2b_param P[1]; // [sp+0h] [bp-C4h] BYREF
  uint8_t block[132]; // [sp+40h] [bp-84h] BYREF

  if ( (unsigned int)(outlen - 1) > 0x3F )
    return -1;
  if ( (unsigned int)(keylen - 1) > 0x3F || key == 0 )
    return -1;
  v5 = keylen;
  P[0].digest_length = outlen;
  P[0].key_length = keylen;
  P[0].leaf_length = 0;
  P[0].node_offset = 0;
  *(_WORD *)&P[0].node_depth = 0;
  *(_DWORD *)P[0].reserved = 0;
  *(_DWORD *)P[0].salt = 0;
  *(_DWORD *)P[0].personal = 0;
  *(_WORD *)&P[0].fanout = 257;
  *(_DWORD *)&P[0].reserved[4] = 0;
  *(_DWORD *)&P[0].reserved[8] = 0;
  *(_WORD *)&P[0].reserved[12] = 0;
  *(_DWORD *)&P[0].salt[4] = 0;
  *(_DWORD *)&P[0].salt[8] = 0;
  *(_DWORD *)&P[0].salt[12] = 0;
  *(_DWORD *)&P[0].personal[4] = 0;
  *(_DWORD *)&P[0].personal[8] = 0;
  *(_DWORD *)&P[0].personal[12] = 0;
  if ( blake2b_init_param(S, P) < 0 )
    return -1;
  memset(block, 0, 0x80u);
  memcpy(block, key, v5);
  blake2b_update(S, block, 0x80u);
  memset_v_6360(block, 0, 0x80u);
  return 0;
}
