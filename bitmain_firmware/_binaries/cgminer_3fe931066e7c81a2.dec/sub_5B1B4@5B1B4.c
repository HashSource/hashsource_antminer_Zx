char *__fastcall sub_5B1B4(const char *a1, _BYTE *a2)
{
  char *result; // r0

  result = sub_5B120(a1, a2);
  if ( !result )
    *a2 ^= 1u;
  return result;
}
