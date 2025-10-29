json_t *__fastcall json_object_get(const json_t *json, const char *key)
{
  if ( !json || json->type )
    return 0;
  else
    return (json_t *)hashtable_get((hashtable_t *)&json[1], key);
}
