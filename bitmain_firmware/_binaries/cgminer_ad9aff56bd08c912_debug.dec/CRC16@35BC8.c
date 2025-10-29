unsigned __int16 __fastcall CRC16(unsigned __int8 *buffer, int len)
{
  int v2; // r4
  unsigned __int8 *v3; // r1
  unsigned int v4; // r2
  int v5; // t1

  if ( !len )
    return -1;
  LOWORD(v2) = 28216;
  v3 = &buffer[len];
  v4 = 0xFFFF;
  do
  {
    v5 = *buffer++;
    HIWORD(v2) = (unsigned int)"s %s():%d" >> 16;
    LOWORD(v4) = *(_WORD *)(v2 + 2 * (v5 ^ (v4 >> 8)) + 100) ^ ((_WORD)v4 << 8);
  }
  while ( buffer != v3 );
  return v4;
}
