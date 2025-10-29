char *__cdecl bin2hex(const unsigned __int8 *p, size_t len)
{
  char *s; // [sp+8h] [bp+8h]
  unsigned int slen; // [sp+Ch] [bp+Ch]

  slen = 2 * len + 1;
  if ( (slen & 3) != 0 )
    slen = (slen & 0xFFFFFFFC) + 4;
  s = (char *)calloc(slen, 1u);
  if ( !s )
    fwrite("Failed to calloc", 1u, 0x10u, (FILE *)stderr);
  _bin2hex(s, p, len);
  return s;
}
