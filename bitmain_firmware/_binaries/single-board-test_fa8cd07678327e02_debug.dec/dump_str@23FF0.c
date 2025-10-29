void __cdecl dump_str(void *fdp, const char *func, unsigned __int8 *str, int len)
{
  char *hexbuff; // [sp+18h] [bp+10h]

  if ( fdp )
  {
    hexbuff = bin2hex(str, len);
    if ( func )
      fprintf((FILE *)fdp, "%s %s len=%d\n", func, hexbuff, len);
    else
      fprintf((FILE *)fdp, "%s\n", hexbuff);
    fflush((FILE *)fdp);
    free(hexbuff);
  }
}
