char *__fastcall Strsep(char **stringp, const char *delim)
{
  char *v3; // r4
  char *v4; // r0

  v3 = *stringp;
  if ( *stringp && (v4 = strpbrk(*stringp, delim)) != 0 )
  {
    *v4 = 0;
    *stringp = v4 + 1;
    return v3;
  }
  else
  {
    *stringp = 0;
    return v3;
  }
}
