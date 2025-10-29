char *__fastcall set_int_0_to_4(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)*i > 4 )
    return "Value out of range";
  return result;
}
