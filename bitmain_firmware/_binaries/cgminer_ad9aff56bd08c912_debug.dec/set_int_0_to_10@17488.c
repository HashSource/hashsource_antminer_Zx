char *__fastcall set_int_0_to_10(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)*i > 0xA )
    return "Value out of range";
  return result;
}
