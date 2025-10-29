const char *__fastcall json_string_value(const json_t *json)
{
  if ( json )
  {
    if ( json->type == JSON_STRING )
      return (const char *)json[1].type;
    else
      return 0;
  }
  return (const char *)json;
}
