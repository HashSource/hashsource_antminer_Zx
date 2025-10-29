json_t *__fastcall json_string_nocheck(const char *value)
{
  _QWORD *v2; // r0
  _QWORD *v3; // r4
  char *v4; // r0
  void *v6; // r0

  if ( !value )
    return 0;
  v2 = jsonp_malloc(0xCu);
  if ( !v2 )
    return 0;
  v3 = v2;
  *v2 = 0x100000002LL;
  v4 = jsonp_strdup(value);
  *((_DWORD *)v3 + 2) = v4;
  if ( !v4 )
  {
    v6 = v3;
    v3 = 0;
    jsonp_free(v6);
  }
  return (json_t *)v3;
}
