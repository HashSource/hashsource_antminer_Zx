int __fastcall blake2b_final(blake2b_state *S, uint8_t *out, uint8_t outlen)
{
  size_t v4; // r9
  _BOOL4 v6; // r3
  size_t buflen; // r12
  uint64_t v8; // r6
  uint64_t v9; // r0
  _BOOL4 v10; // r3
  int last_node; // lr
  size_t *p_buflen; // r0
  uint8_t *v13; // r3
  uint64_t *v14; // r4
  size_t v15; // t1
  size_t v16; // r2
  bool v18; // cf
  int v19; // r3
  size_t v20; // r2
  uint64_t v21; // [sp+0h] [bp-4Ch]
  uint8_t buffer[64]; // [sp+8h] [bp-44h] BYREF

  v4 = outlen;
  memset(buffer, 0, sizeof(buffer));
  v6 = out == 0;
  if ( v4 - 1 > 0x3F )
    v6 = 1;
  if ( v6 || S->f[0] )
    return -1;
  buflen = S->buflen;
  v8 = S->t[0];
  v21 = S->t[1];
  if ( buflen > 0x80 )
  {
    v18 = 1;
    if ( !((v8 + 128) >> 32) )
      v18 = (unsigned int)v8 < 0xFFFFFF80;
    S->t[0] = v8 + 128;
    v19 = !v18;
    S->t[1] = v21 + (unsigned int)v19;
    blake2b_compress(S, S->buf);
    v20 = S->buflen - 128;
    S->buflen = v20;
    memcpy(S->buf, &S->buf[128], v20);
    buflen = S->buflen;
    v8 = S->t[0];
    v21 = S->t[1];
  }
  v9 = v8 + buflen;
  v10 = __CFADD__(HIDWORD(v8), HIDWORD(v9));
  last_node = S->last_node;
  S->t[0] = v9;
  S->t[1] = v21 + v10;
  if ( last_node )
    S->f[1] = -1;
  S->f[0] = -1;
  memset(&S->buf[buflen], 0, 256 - buflen);
  blake2b_compress(S, S->buf);
  p_buflen = &S[-1].buflen;
  v13 = buffer;
  v14 = &S->h[7];
  do
  {
    v15 = p_buflen[2];
    p_buflen += 2;
    v13 += 8;
    v16 = p_buflen[1];
    *(v13 - 8) = v15;
    *(v13 - 4) = v16;
    *(v13 - 7) = BYTE1(v15);
    *(v13 - 3) = BYTE1(v16);
    *(v13 - 2) = BYTE2(v16);
    *(v13 - 1) = HIBYTE(v16);
    *((_WORD *)v13 - 3) = HIWORD(v15);
  }
  while ( v14 != (uint64_t *)p_buflen );
  memcpy(out, buffer, v4);
  return 0;
}
