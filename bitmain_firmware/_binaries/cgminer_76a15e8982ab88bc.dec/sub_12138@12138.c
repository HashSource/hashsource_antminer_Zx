char *__fastcall sub_12138(const char *a1, float *a2)
{
  char *result; // r0

  result = sub_58598(a1, a2);
  if ( !result && (*a2 < 125.0 || *a2 > 500.0) )
    return "Value out of range";
  return result;
}
