uint16_t __fastcall crc_itu_t(uint16_t crc, const uint8_t *buffer, int len)
{
  const uint8_t *v3; // r2
  int v4; // t1

  if ( len )
  {
    v3 = &buffer[len];
    do
    {
      v4 = *buffer++;
      crc = *(_WORD *)&_FUNCTION___15596[2 * (v4 ^ HIBYTE(crc)) + 100] ^ (crc << 8);
    }
    while ( buffer != v3 );
  }
  return crc;
}
