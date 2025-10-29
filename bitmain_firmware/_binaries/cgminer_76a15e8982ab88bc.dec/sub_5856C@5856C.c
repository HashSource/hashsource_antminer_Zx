char *__fastcall sub_5856C(const char *a1, _BYTE *a2)
{
  char *result; // r0

  result = sub_584D8(a1, a2);
  if ( !result )
    *a2 ^= 1u;
  return result;
}
