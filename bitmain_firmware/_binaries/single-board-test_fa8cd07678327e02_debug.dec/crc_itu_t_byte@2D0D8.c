unsigned __int16 __cdecl crc_itu_t_byte(unsigned __int16 crc, const unsigned __int8 data)
{
  return crc_itu_t_table[(unsigned __int8)(data ^ HIBYTE(crc))] ^ (crc << 8);
}
