char *__fastcall sub_16D98(char *s)
{
  if ( !dword_76F24 )
    dword_76F24 = (int)_strdup(s);
  if ( ++dword_76F28 <= 10 )
    return sub_16CB0(s);
  else
    return "Too many levels of JSON includes (limit 10) or a loop";
}
