int __cdecl blake2b(
        uint8_t *out,
        const void *in,
        const void *key,
        const uint8_t outlen,
        const uint64_t inlen,
        uint8_t keylen)
{
  blake2b_state S[1]; // [sp+10h] [bp+10h] BYREF

  if ( !in && inlen )
    return -1;
  if ( !out )
    return -1;
  if ( !key && keylen )
    return -1;
  if ( !outlen || outlen > 0x40u )
    return -1;
  if ( keylen <= 0x40u )
  {
    if ( keylen )
    {
      if ( blake2b_init_key(S, outlen, key, keylen) < 0 )
        return -1;
    }
    else if ( blake2b_init(S, outlen) < 0 )
    {
      return -1;
    }
    blake2b_update(S, (const uint8_t *)in, inlen);
    blake2b_final(S, out, outlen);
    return 0;
  }
  return -1;
}
