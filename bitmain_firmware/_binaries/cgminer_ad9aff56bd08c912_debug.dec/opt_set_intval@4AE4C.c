char *__fastcall opt_set_intval(const char *arg, int *i)
{
  char *result; // r0
  int l; // [sp+4h] [bp-4h] BYREF

  result = opt_set_longval(arg, &l);
  if ( !result )
    *i = l;
  return result;
}
