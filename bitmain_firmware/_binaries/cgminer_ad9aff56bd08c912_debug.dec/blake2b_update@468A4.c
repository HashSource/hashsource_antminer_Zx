int __fastcall blake2b_update(blake2b_state *S, const uint8_t *in, uint64_t inlen)
{
  uint64_t v3; // r10
  size_t buflen; // r0
  bool v7; // cf
  uint8_t *buf; // r7
  size_t v9; // r5
  size_t v10; // r8
  const uint8_t *v11; // r1
  bool v12; // cf
  uint64_t v14; // [sp+0h] [bp-1Ch]
  uint64_t v15; // [sp+8h] [bp-14h]

  v3 = inlen;
  if ( inlen )
  {
    buflen = S->buflen;
    v7 = HIDWORD(inlen) == 0;
    buf = S->buf;
    v9 = 256 - buflen;
    if ( !HIDWORD(inlen) )
      v7 = v9 >= (unsigned int)inlen;
    v10 = 256 - buflen;
    if ( !v7 )
    {
      do
      {
        v11 = in;
        in += v9;
        memcpy(&buf[buflen], v11, v9);
        v15 = S->t[1];
        v14 = S->t[0] + 128;
        S->t[0] = v14;
        S->buflen += v9;
        S->t[1] = v15 + (v14 < 0x80);
        blake2b_compress(S, S->buf);
        memcpy(S->buf, &S->buf[128], 0x80u);
        v3 -= v10;
        v12 = HIDWORD(v3) == 0;
        buflen = S->buflen - 128;
        v9 = 384 - S->buflen;
        S->buflen = buflen;
        if ( !HIDWORD(v3) )
          v12 = v9 >= (unsigned int)v3;
        v10 = v9;
      }
      while ( !v12 );
    }
    memcpy(&buf[buflen], in, v3);
    S->buflen += v3;
  }
  return 0;
}
