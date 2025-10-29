int __fastcall blake2b(
        uint8_t *out,
        const void *in,
        const void *key,
        const uint8_t outlen,
        const uint64_t inlen,
        uint8_t keylen)
{
  _BOOL4 v6; // r4
  int v7; // r4
  bool v8; // cc
  blake2b_state S[1]; // [sp+0h] [bp-16Ch] BYREF

  v6 = inlen != 0;
  if ( in )
    v6 = 0;
  if ( !out )
    v6 = 1;
  if ( v6 )
    return -1;
  v7 = keylen;
  if ( keylen )
    v7 = 1;
  if ( key )
    v7 = 0;
  if ( v7 )
    return -1;
  v8 = keylen > 0x40u;
  if ( keylen <= 0x40u )
    v8 = (unsigned int)(outlen - 1) > 0x3F;
  if ( v8 )
    return -1;
  if ( keylen )
  {
    if ( blake2b_init_key(S, outlen, key, keylen) >= 0 )
      goto LABEL_16;
    return -1;
  }
  if ( blake2b_init(S, outlen) < 0 )
    return -1;
LABEL_16:
  blake2b_update(S, (const uint8_t *)in, inlen);
  blake2b_final(S, out, outlen);
  return 0;
}
