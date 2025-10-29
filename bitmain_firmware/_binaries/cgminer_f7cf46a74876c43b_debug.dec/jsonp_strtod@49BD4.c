int __fastcall jsonp_strtod(strbuffer_t *strbuffer, double *out)
{
  double v2; // d0
  struct lconv *v5; // r0
  char *value; // r5
  int v7; // r6
  char *v8; // r0
  int *v9; // r6
  int result; // r0
  char *end; // [sp+4h] [bp-8h] BYREF

  v5 = localeconv();
  value = strbuffer->value;
  v7 = *(unsigned __int8 *)v5->decimal_point;
  if ( v7 != 46 )
  {
    v8 = strchr(strbuffer->value, 46);
    if ( v8 )
    {
      *v8 = v7;
      value = strbuffer->value;
    }
  }
  v9 = _errno_location();
  *v9 = 0;
  strtod(value, &end);
  if ( end != &strbuffer->value[strbuffer->length] )
    _assert_fail("end == strbuffer->value + strbuffer->length", "strconv.c", 0x46u, "jsonp_strtod");
  result = *v9 == 34 && v2 != 0.0;
  if ( result )
    return -1;
  *out = v2;
  return result;
}
