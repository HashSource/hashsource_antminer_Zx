unsigned __int16 __fastcall CRC16(unsigned __int8 *buffer, int len)
{
  unsigned __int8 *v2; // r1
  unsigned int v3; // r2
  int v4; // t1

  if ( !len )
    return -1;
  v2 = &buffer[len];
  v3 = 0xFFFF;
  do
  {
    v4 = *buffer++;
    LOWORD(v3) = *(_WORD *)&_FUNCTION___15596[2 * (v4 ^ (v3 >> 8)) + 100] ^ ((_WORD)v3 << 8);
  }
  while ( buffer != v2 );
  return v3;
}
