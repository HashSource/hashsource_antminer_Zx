const char *__fastcall utf8_iterate(const char *buffer, int32_t *codepoint)
{
  const char *v2; // r4
  int v4; // r0
  int32_t v5; // r2
  int v6; // r6
  int32_t value; // [sp+4h] [bp-4h] BYREF

  if ( !*buffer )
    return buffer;
  v2 = buffer;
  v4 = utf8_check_first(*buffer);
  v6 = v4;
  if ( v4 <= 0 )
    return 0;
  if ( v4 != 1 )
  {
    if ( utf8_check_full(v2, v4, &value) )
      goto LABEL_6;
    return 0;
  }
  value = v5;
LABEL_6:
  if ( codepoint )
    *codepoint = value;
  return &v2[v6];
}
