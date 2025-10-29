_BYTE *__fastcall sub_153E4(int a1, unsigned int a2)
{
  _BYTE *result; // r0

  result = *(_BYTE **)(a1 + 308);
  *(_DWORD *)(a1 + 68) = bswap32(a2);
  if ( result )
  {
    free(result);
    result = sub_294B8(a1 + 68, 4);
    *(_DWORD *)(a1 + 308) = result;
  }
  return result;
}
