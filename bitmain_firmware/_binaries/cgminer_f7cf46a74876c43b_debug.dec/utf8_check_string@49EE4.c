int __fastcall utf8_check_string(const char *string, int length)
{
  int v3; // r8
  int v4; // r4
  int v5; // r0
  int v6; // r5

  if ( length == -1 )
    v3 = strlen(string);
  else
    v3 = length;
  if ( v3 <= 0 )
    return 1;
  v4 = 0;
  while ( 1 )
  {
    v5 = utf8_check_first(string[v4]);
    v6 = v5;
    if ( !v5 )
      break;
    if ( v5 > 1 )
    {
      if ( v5 + v4 > v3 || !utf8_check_full(&string[v4], v5, 0) )
        return 0;
      v4 += v6 - 1;
    }
    if ( v3 <= ++v4 )
      return 1;
  }
  return 0;
}
