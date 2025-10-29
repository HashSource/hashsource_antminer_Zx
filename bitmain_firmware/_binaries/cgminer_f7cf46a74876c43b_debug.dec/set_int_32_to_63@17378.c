char *__fastcall set_int_32_to_63(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)(*i - 32) > 0x1F )
    return "Value out of range";
  return result;
}
