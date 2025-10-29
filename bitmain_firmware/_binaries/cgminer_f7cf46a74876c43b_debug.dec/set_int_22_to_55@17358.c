char *__fastcall set_int_22_to_55(const char *arg, int *i)
{
  char *result; // r0

  result = opt_set_intval(arg, i);
  if ( !result && (unsigned int)(*i - 22) > 0x21 )
    return "Value out of range";
  return result;
}
