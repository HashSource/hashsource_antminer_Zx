char *__fastcall opt_set_ulongval(const char *arg, unsigned int *ul)
{
  char *result; // r0
  bool v5; // nf
  int l; // [sp+4h] [bp-8h] BYREF

  result = opt_set_longval(arg, &l);
  if ( !result )
  {
    v5 = l < 0;
    *ul = l;
    if ( v5 )
      return arg_bad("'%s' is negative", arg);
  }
  return result;
}
