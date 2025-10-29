char *__fastcall set_int_1_to_65535(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)(*i - 1) > 0xFFFE )
    return "Value out of range";
  return result;
}
