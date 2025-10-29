int __fastcall json_string_set(json_t *json, const char *value)
{
  if ( !value )
    return -1;
  if ( utf8_check_string(value, -1) )
    return json_string_set_nocheck(json, value);
  return -1;
}
