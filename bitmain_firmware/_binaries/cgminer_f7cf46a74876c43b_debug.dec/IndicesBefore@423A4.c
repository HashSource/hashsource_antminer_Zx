bool __fastcall IndicesBefore(const uint8_t *a, const uint8_t *b, size_t hashLen, uint32_t indicesLen)
{
  return (unsigned int)memcmp(&a[hashLen], &b[hashLen], indicesLen) >> 31;
}
