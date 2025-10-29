void **__fastcall sub_2AE2C(void **result, unsigned int a2, size_t a3, const char *a4, const char *a5, int a6)
{
  void **v8; // r6
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v8 = result;
  if ( a3 != a2 )
  {
    result = (void **)realloc(*result, a3);
    *v8 = result;
    if ( !result )
    {
      snprintf(s, 0x1000u, "Failed to realloc in %s %s():%d", a4, a5, a6);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    if ( a3 > a2 )
      return (void **)memset((char *)*v8 + a2, 0, a3 - a2);
  }
  return result;
}
