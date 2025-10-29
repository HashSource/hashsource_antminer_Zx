char *__fastcall set_int_1_to_10(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)(*i - 1) > 9 )
    return "Value out of range";
  return result;
}
