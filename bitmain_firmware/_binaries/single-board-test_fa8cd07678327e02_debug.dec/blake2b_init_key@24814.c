int __cdecl blake2b_init_key(blake2b_state *S, const uint8_t outlen, const void *key, const uint8_t keylen)
{
  uint8_t block[128]; // [sp+10h] [bp+10h] BYREF
  blake2b_param P[1]; // [sp+90h] [bp+90h] BYREF

  if ( !outlen || outlen > 0x40u )
    return -1;
  if ( !key || !keylen || keylen > 0x40u )
    return -1;
  P[0].digest_length = outlen;
  P[0].key_length = keylen;
  P[0].fanout = 1;
  P[0].depth = 1;
  store32(&P[0].leaf_length, 0);
  store64(&P[0].node_offset, 0);
  P[0].node_depth = 0;
  P[0].inner_length = 0;
  memset(P[0].reserved, 0, sizeof(P[0].reserved));
  memset(P[0].salt, 0, sizeof(P[0].salt));
  memset(P[0].personal, 0, sizeof(P[0].personal));
  if ( blake2b_init_param(S, P) < 0 )
    return -1;
  memset(block, 0, sizeof(block));
  memcpy(block, key, keylen);
  blake2b_update(S, block, 0x80u);
  secure_zero_memory(block, 0x80u);
  return 0;
}
