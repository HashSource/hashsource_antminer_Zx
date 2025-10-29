int __fastcall json_object_iter_set_new(json_t *json, void *iter, json_t *value)
{
  if ( !json )
    return -1;
  if ( json->type )
    return -1;
  if ( !iter || value == 0 )
    return -1;
  hashtable_iter_set(iter, value);
  return 0;
}
