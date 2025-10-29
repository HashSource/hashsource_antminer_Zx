unsigned __int16 __fastcall crc16(const unsigned __int8 *buffer, int len)
{
  const unsigned __int8 *v2; // r1
  unsigned int v3; // r3
  int v4; // t1

  if ( len <= 0 )
    return 0;
  v2 = &buffer[len];
  v3 = 0;
  do
  {
    v4 = *buffer++;
    v3 = LOWORD(crc16_table[v4 ^ (v3 >> 8)]) ^ (unsigned __int16)((_WORD)v3 << 8);
  }
  while ( buffer != v2 );
  return v3;
}
