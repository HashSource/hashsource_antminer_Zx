void __cdecl Sha256_Final(CSha256 *p, uint8_t *digest)
{
  int v2; // r3
  uint32_t v3; // r3
  uint32_t v4; // r1
  uint8_t *v5; // r3
  unsigned int i; // [sp+8h] [bp+8h]
  unsigned int ia; // [sp+8h] [bp+8h]
  uint32_t curBufferPos; // [sp+Ch] [bp+Ch]
  uint32_t curBufferPosa; // [sp+Ch] [bp+Ch]
  uint64_t lenInBits; // [sp+10h] [bp+10h]

  lenInBits = 8 * p->count;
  v2 = p->count & 0x3F;
  curBufferPos = v2 + 1;
  p->buffer[v2] = 0x80;
  while ( curBufferPos != 56 )
  {
    curBufferPosa = curBufferPos & 0x3F;
    if ( !curBufferPosa )
      Sha256_WriteByteBlock(p);
    v3 = curBufferPosa;
    curBufferPos = curBufferPosa + 1;
    p->buffer[v3] = 0;
  }
  for ( i = 0; i <= 7; ++i )
  {
    v4 = curBufferPos++;
    p->buffer[v4] = HIBYTE(lenInBits);
    lenInBits <<= 8;
  }
  Sha256_WriteByteBlock(p);
  for ( ia = 0; ia <= 7; ++ia )
  {
    *digest = HIBYTE(p->state[ia]);
    digest[1] = BYTE2(p->state[ia]);
    digest[2] = BYTE1(p->state[ia]);
    v5 = digest + 3;
    digest += 4;
    *v5 = p->state[ia];
  }
  Sha256_Init(p);
}
