char *__cdecl s_hexdump(const void *_a, uint32_t a_len)
{
  uint32_t i; // [sp+Ch] [bp+Ch]

  for ( i = 0; i < a_len && i + 2 < 0x1000; ++i )
    sprintf(&buf_7545[2 * i], "%02x", *((unsigned __int8 *)_a + i));
  buf_7545[2 * i] = 0;
  return buf_7545;
}
