char *__fastcall opt_set_invbool_arg(const char *arg, bool *b)
{
  char *result; // r0

  result = opt_set_bool_arg(arg, b);
  if ( !result )
    *b ^= 1u;
  return result;
}
