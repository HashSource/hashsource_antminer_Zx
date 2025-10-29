char *__fastcall opt_set_uintval(const char *arg, unsigned int *ui)
{
  char *result; // r0
  int l; // [sp+4h] [bp-8h] BYREF

  result = opt_set_longval(arg, &l);
  if ( !result )
  {
    if ( l < 0 )
      return arg_bad("'%s' is negative", arg);
    else
      *ui = l;
  }
  return result;
}
