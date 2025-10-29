char *__fastcall opt_set_longval(const char *arg, int *l)
{
  int *v4; // r5
  int v5; // r0
  char *v6; // r3
  char *result; // r0
  char *endp; // [sp+4h] [bp-4h] BYREF

  v4 = _errno_location();
  *v4 = 0;
  v5 = strtol(arg, &endp, 0);
  v6 = endp;
  *l = v5;
  if ( *v6 || !*arg )
    return arg_bad("'%s' is not a number", arg);
  result = (char *)*v4;
  if ( *v4 )
    return arg_bad("'%s' is out of range", arg);
  return result;
}
