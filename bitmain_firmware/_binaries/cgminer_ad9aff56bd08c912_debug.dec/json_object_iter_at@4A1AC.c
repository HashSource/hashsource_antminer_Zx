void *__fastcall json_object_iter_at(json_t *json, const char *key)
{
  bool v2; // zf

  v2 = json == 0;
  if ( json )
    v2 = key == 0;
  if ( v2 || json->type )
    return 0;
  else
    return hashtable_iter_at((hashtable_t *)&json[1], key);
}
