int __fastcall json_string_set_nocheck(json_t *json, const char *value)
{
  char *v4; // r6

  if ( !json )
    return -1;
  if ( json->type != JSON_STRING || value == 0 )
    return -1;
  v4 = jsonp_strdup(value);
  if ( !v4 )
    return -1;
  jsonp_free((void *)json[1].type);
  json[1].type = (json_type)v4;
  return 0;
}
