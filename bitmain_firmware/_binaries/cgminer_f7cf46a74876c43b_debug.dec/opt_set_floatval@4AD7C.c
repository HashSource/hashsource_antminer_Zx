char *__fastcall opt_set_floatval(const char *arg, float *f)
{
  int v2; // s0
  int *v5; // r5
  char *v6; // r3
  char *result; // r0
  char *endp; // [sp+4h] [bp-4h] BYREF

  v5 = _errno_location();
  *v5 = 0;
  strtof(arg, &endp);
  v6 = endp;
  *(_DWORD *)f = v2;
  if ( *v6 || !*arg )
    return arg_bad("'%s' is not a number", arg);
  result = (char *)*v5;
  if ( *v5 )
    return arg_bad("'%s' is out of range", arg);
  return result;
}
