char *__fastcall _json_array_string(json_t *val, unsigned int entry)
{
  json_t *v4; // r0

  if ( !val )
    return 0;
  if ( val->type == JSON_ARRAY && json_array_size(val) >= entry )
  {
    v4 = json_array_get(val, entry);
    if ( v4 )
    {
      if ( v4->type == JSON_STRING )
        return (char *)json_string_value(v4);
    }
  }
  return 0;
}
