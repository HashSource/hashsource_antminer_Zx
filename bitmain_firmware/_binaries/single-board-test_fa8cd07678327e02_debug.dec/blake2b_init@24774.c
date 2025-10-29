int __cdecl blake2b_init(blake2b_state *S, const uint8_t outlen)
{
  blake2b_param P[1]; // [sp+8h] [bp+8h] BYREF

  if ( !outlen || outlen > 0x40u )
    return -1;
  P[0].digest_length = outlen;
  P[0].key_length = 0;
  P[0].fanout = 1;
  P[0].depth = 1;
  store32(&P[0].leaf_length, 0);
  store64(&P[0].node_offset, 0);
  P[0].node_depth = 0;
  P[0].inner_length = 0;
  memset(P[0].reserved, 0, sizeof(P[0].reserved));
  memset(P[0].salt, 0, sizeof(P[0].salt));
  memset(P[0].personal, 0, sizeof(P[0].personal));
  return blake2b_init_param(S, P);
}
