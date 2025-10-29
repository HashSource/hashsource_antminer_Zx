void __cdecl Sha256_Update(CSha256 *p, const uint8_t *data, size_t size)
{
  uint32_t v3; // r3
  uint8_t *v4; // r2
  uint32_t curBufferPos; // [sp+14h] [bp+14h]

  curBufferPos = p->count & 0x3F;
  while ( size )
  {
    v3 = curBufferPos++;
    v4 = (uint8_t *)data++;
    p->buffer[v3] = *v4;
    ++p->count;
    --size;
    if ( curBufferPos == 64 )
    {
      curBufferPos = 0;
      Sha256_WriteByteBlock(p);
    }
  }
}
