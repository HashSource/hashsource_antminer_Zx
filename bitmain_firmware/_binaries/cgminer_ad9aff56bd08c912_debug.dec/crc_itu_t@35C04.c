uint16_t __fastcall crc_itu_t(uint16_t crc, const uint8_t *buffer, int len)
{
  int v3; // r4
  const uint8_t *v4; // r2
  int v5; // t1

  if ( len )
  {
    LOWORD(v3) = 28216;
    v4 = &buffer[len];
    do
    {
      v5 = *buffer++;
      HIWORD(v3) = (unsigned int)"s %s():%d" >> 16;
      crc = *(_WORD *)(v3 + 2 * (v5 ^ HIBYTE(crc)) + 100) ^ (crc << 8);
    }
    while ( buffer != v4 );
  }
  return crc;
}
