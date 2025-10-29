char *__fastcall sub_16CD0(char *s)
{
  if ( !dword_73D5C )
    dword_73D5C = (int)_strdup(s);
  if ( ++dword_73D60 <= 10 )
    return sub_16BE8(s);
  else
    return "Too many levels of JSON includes (limit 10) or a loop";
}
