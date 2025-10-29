void __fastcall Sha256_Final(CSha256 *p, uint8_t *digest)
{
  uint8_t v2; // r10
  unsigned int count; // r3
  char v6; // r7
  unsigned int v7; // r9
  int v8; // r4
  int v9; // r4
  int v10; // r6
  CSha256 *v11; // r2
  int v12; // r3
  uint8_t *v13; // r3
  uint8_t *v14; // r2
  uint8_t *v15; // r8
  int v16; // t1

  count = p->count;
  v6 = (count & 0x3F) + 1;
  v7 = 8 * count;
  v8 = 8 * HIDWORD(p->count);
  p->buffer[count & 0x3F] = 0x80;
  if ( (count & 0x3F) != 0x37 )
    v2 = 0;
  v9 = v8 | (count >> 29);
  if ( (count & 0x3F) != 0x37 )
  {
    do
    {
      while ( 1 )
      {
        v10 = v6 & 0x3F;
        v6 = v10 + 1;
        if ( v10 )
          break;
        Sha256_WriteByteBlock(p);
        p->buffer[0] = 0;
      }
      p->buffer[v10] = v2;
    }
    while ( v10 != 55 );
  }
  v11 = (CSha256 *)&p->buffer[56];
  do
  {
    v12 = (v9 << 8) | HIBYTE(v7);
    LOBYTE(v11->state[0]) = HIBYTE(v9);
    v11 = (CSha256 *)((char *)v11 + 1);
    v7 <<= 8;
    v9 = v12;
  }
  while ( v11 != &p[1] );
  Sha256_WriteByteBlock(p);
  v13 = digest + 4;
  v14 = &p[-1].buffer[60];
  v15 = digest + 36;
  do
  {
    v16 = *((_DWORD *)v14 + 1);
    v14 += 4;
    v13 += 4;
    *(v13 - 8) = HIBYTE(v16);
    *(v13 - 7) = *((_WORD *)v14 + 1);
    *(v13 - 6) = BYTE1(*(_DWORD *)v14);
    *(v13 - 5) = *(_DWORD *)v14;
  }
  while ( v13 != v15 );
  p->state[0] = 1779033703;
  p->state[1] = -1150833019;
  p->state[2] = 1013904242;
  p->state[3] = -1521486534;
  p->state[4] = 1359893119;
  p->state[5] = -1694144372;
  p->state[6] = 528734635;
  p->state[7] = 1541459225;
  p->count = 0;
}
