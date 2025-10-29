int __fastcall json_integer_set(json_t *json, int a2, json_t value)
{
  if ( !json || json->type != JSON_INTEGER )
    return -1;
  json[1] = value;
  return 0;
}
