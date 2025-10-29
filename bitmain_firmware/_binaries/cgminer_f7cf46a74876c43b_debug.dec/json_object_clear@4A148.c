int __fastcall json_object_clear(json_t *json)
{
  if ( !json )
    return -1;
  if ( json->type )
    return -1;
  hashtable_clear((hashtable_t *)&json[1]);
  json[3].refcount = 0;
  return 0;
}
