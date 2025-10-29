char *__fastcall jsonp_strdup(const char *str)
{
  size_t v2; // r4
  char *v3; // r0
  char *v4; // r5

  v2 = strlen(str) + 1;
  v3 = (char *)do_malloc(v2);
  v4 = v3;
  if ( v3 )
    memcpy(v3, str, v2);
  return v4;
}
