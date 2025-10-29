char *__fastcall set_int_range(const char *arg, int *i, int min, int max)
{
  char *result; // r0
  _BOOL4 v8; // r4
  int v9; // r3

  result = opt_set_intval(arg, i);
  if ( !result )
  {
    v8 = *i < min;
    if ( *i > max )
      v9 = v8 | 1;
    else
      v9 = v8;
    if ( v9 )
      return "Value out of range";
  }
  return result;
}
