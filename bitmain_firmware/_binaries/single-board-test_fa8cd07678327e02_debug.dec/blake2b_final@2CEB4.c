int __cdecl blake2b_final(blake2b_state *S, uint8_t *out, uint8_t outlen)
{
  uint8_t buffer[64]; // [sp+14h] [bp+14h] BYREF
  int i; // [sp+54h] [bp+54h]

  memset(buffer, 0, sizeof(buffer));
  if ( !out || !outlen || outlen > 0x40u )
    return -1;
  if ( blake2b_is_lastblock(S) )
    return -1;
  if ( S->buflen > 0x80 )
  {
    blake2b_increment_counter(S, 0x80u);
    blake2b_compress(S, S->buf);
    S->buflen -= 128;
    memcpy(S->buf, &S->buf[128], S->buflen);
  }
  blake2b_increment_counter(S, S->buflen);
  blake2b_set_lastblock(S);
  memset(&S->buf[S->buflen], 0, 256 - S->buflen);
  blake2b_compress(S, S->buf);
  for ( i = 0; i <= 7; ++i )
    store64(&buffer[8 * i], S->h[i]);
  memcpy(out, buffer, outlen);
  return 0;
}
