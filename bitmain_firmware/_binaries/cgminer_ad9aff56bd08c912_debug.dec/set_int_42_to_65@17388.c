char *__fastcall set_int_42_to_65(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)(*i - 42) > 0x14 )
    return "Value out of range";
  return result;
}
