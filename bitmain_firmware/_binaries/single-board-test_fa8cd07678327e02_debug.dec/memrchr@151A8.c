void *__cdecl memrchr(const void *s, int c, size_t n)
{
  const char *end; // [sp+14h] [bp+14h]

  end = (char *)s + n;
  while ( --end >= s )
  {
    if ( *(unsigned __int8 *)end == c )
      return (void *)end;
  }
  return 0;
}
