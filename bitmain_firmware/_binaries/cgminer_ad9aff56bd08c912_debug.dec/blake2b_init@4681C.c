int __fastcall blake2b_init(blake2b_state *S, const uint8_t outlen)
{
  blake2b_param P[1]; // [sp+0h] [bp-48h] BYREF

  if ( (unsigned int)(outlen - 1) > 0x3F )
    return -1;
  P[0].digest_length = outlen;
  P[0].key_length = 0;
  P[0].leaf_length = 0;
  P[0].node_offset = 0;
  P[0].node_depth = 0;
  P[0].inner_length = 0;
  *(_DWORD *)P[0].reserved = 0;
  *(_DWORD *)P[0].salt = 0;
  *(_DWORD *)P[0].personal = 0;
  *(_DWORD *)&P[0].reserved[4] = 0;
  *(_DWORD *)&P[0].reserved[8] = 0;
  *(_WORD *)&P[0].reserved[12] = 0;
  *(_DWORD *)&P[0].salt[4] = 0;
  *(_DWORD *)&P[0].salt[8] = 0;
  *(_DWORD *)&P[0].salt[12] = 0;
  *(_DWORD *)&P[0].personal[4] = 0;
  *(_DWORD *)&P[0].personal[8] = 0;
  *(_DWORD *)&P[0].personal[12] = 0;
  P[0].fanout = 1;
  P[0].depth = 1;
  return blake2b_init_param(S, P);
}
