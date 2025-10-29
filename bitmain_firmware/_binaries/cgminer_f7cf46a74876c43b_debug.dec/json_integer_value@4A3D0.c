json_int_t __fastcall json_integer_value(const json_t *json)
{
  if ( json && json->type == JSON_INTEGER )
    return (json_int_t)json[1];
  else
    return 0;
}
