char *__fastcall sub_15394(const char *a1, _DWORD *a2, int a3, int a4)
{
  char *result; // r0

  result = sub_586A0(a1, a2);
  if ( !result && (*a2 < a3 || *a2 > a4) )
    return "Value out of range";
  return result;
}
