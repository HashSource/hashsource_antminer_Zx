int __cdecl blake2b_update(blake2b_state *S, const uint8_t *in, uint64_t inlen)
{
  size_t fill; // [sp+10h] [bp+10h]
  size_t left; // [sp+14h] [bp+14h]

  while ( inlen )
  {
    left = S->buflen;
    fill = 256 - left;
    if ( 256 - left >= inlen )
    {
      memcpy(&S->buf[left], in, inlen);
      S->buflen += inlen;
      in += inlen;
      inlen = 0;
    }
    else
    {
      memcpy(&S->buf[left], in, fill);
      S->buflen += fill;
      blake2b_increment_counter(S, 0x80u);
      blake2b_compress(S, S->buf);
      memcpy(S->buf, &S->buf[128], 0x80u);
      S->buflen -= 128;
      in += fill;
      inlen -= fill;
    }
  }
  return 0;
}
