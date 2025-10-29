char *__fastcall sub_120E8(const char *a1, float *a2)
{
  char *result; // r0

  result = sub_58598(a1, a2);
  if ( !result && (*a2 < 100.0 || *a2 > 250.0) )
    return "Value out of range";
  return result;
}
