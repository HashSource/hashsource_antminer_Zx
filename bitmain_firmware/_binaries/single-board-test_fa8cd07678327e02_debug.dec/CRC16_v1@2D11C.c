unsigned __int16 __cdecl CRC16_v1(const unsigned __int8 *buffer, int len)
{
  const unsigned __int8 *v2; // r3
  __int16 crc; // [sp+Eh] [bp+Eh]

  for ( crc = -1; len--; crc = crc_itu_t_byte(crc, *v2) )
    v2 = buffer++;
  return crc;
}
