char *__fastcall sub_5AFB0(char *result, char *s)
{
  bool v2; // zf
  char *v4; // r5
  size_t v5; // r0

  v2 = result == 0;
  if ( result )
    v2 = s == 0;
  v4 = result;
  if ( !v2 )
  {
    v5 = strlen(s);
    if ( v5 <= 0x4F )
    {
      return (char *)memcpy(v4 + 12, s, v5 + 1);
    }
    else
    {
      strcpy(v4 + 12, "...");
      return strcpy(v4 + 15, &s[v5 - 76]);
    }
  }
  return result;
}
