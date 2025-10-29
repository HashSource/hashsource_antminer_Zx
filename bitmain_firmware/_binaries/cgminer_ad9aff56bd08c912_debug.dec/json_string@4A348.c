json_t *__fastcall json_string(const char *value)
{
  if ( !value )
    return 0;
  if ( utf8_check_string(value, -1) )
    return json_string_nocheck(value);
  return 0;
}
