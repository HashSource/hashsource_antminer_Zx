int __cdecl getIndices(
        const uint8_t *hash,
        size_t len,
        size_t lenIndices,
        size_t cBitLen,
        uint8_t *data,
        size_t maxLen)
{
  if ( cBitLen + 8 > 0x27 )
    _assert_fail("((cBitLen + 1) + 7) / 8 <= sizeof(uint32_t)", "bm174x/equihash-verify.c", 0x6Cu, "getIndices");
  if ( (lenIndices * (cBitLen + 1)) >> 5 > maxLen )
    return -1;
  if ( data )
    compressArray(
      &hash[len],
      lenIndices,
      data,
      (lenIndices * (cBitLen + 1)) >> 5,
      cBitLen + 1,
      4 - ((cBitLen + 8) >> 3));
  return (lenIndices * (cBitLen + 1)) >> 5;
}
