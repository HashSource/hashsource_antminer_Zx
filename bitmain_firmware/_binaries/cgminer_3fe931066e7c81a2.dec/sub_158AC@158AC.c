_BYTE *__fastcall sub_158AC(int a1, unsigned int a2)
{
  _BYTE *result; // r0

  result = *(_BYTE **)(a1 + 1796);
  *(_DWORD *)(a1 + 68) = bswap32(a2);
  if ( result )
  {
    free(result);
    result = sub_29730(a1 + 68, 4);
    *(_DWORD *)(a1 + 1796) = result;
  }
  return result;
}
