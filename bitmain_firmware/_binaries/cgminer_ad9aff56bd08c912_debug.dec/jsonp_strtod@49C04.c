int __fastcall jsonp_strtod(strbuffer_t *strbuffer, double *out)
{
  double v2; // d0
  struct lconv *v5; // r0
  char *value; // r5
  int v7; // r6
  char *v8; // r0
  int *v9; // r6
  int result; // r0
  const char *v11; // r3
  const char *v12; // r1
  const char *v13; // r0
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
  {
    LOWORD(v11) = -19308;
    LOWORD(v12) = -19292;
    LOWORD(v13) = -19280;
    HIWORD(v11) = (unsigned int)"<stream>" >> 16;
    HIWORD(v12) = (unsigned int)"le to open %s: %s" >> 16;
    HIWORD(v13) = (unsigned int)"s: %s" >> 16;
    _assert_fail(v13, v12, 0x46u, v11);
  }
  result = *v9 == 34 && v2 != 0.0;
  if ( result )
    return -1;
  *out = v2;
  return result;
}
