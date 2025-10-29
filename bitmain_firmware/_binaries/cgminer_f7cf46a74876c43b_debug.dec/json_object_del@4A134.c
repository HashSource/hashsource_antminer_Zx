int __fastcall json_object_del(json_t *json, const char *key)
{
  if ( !json || json->type )
    return -1;
  else
    return hashtable_del((hashtable_t *)&json[1], key);
}
