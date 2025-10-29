void *__fastcall json_object_iter_next(json_t *json, void *iter)
{
  _BOOL4 v2; // r3

  if ( !json )
    return 0;
  v2 = iter == 0;
  if ( json->type )
    v2 = 1;
  if ( v2 )
    return 0;
  else
    return hashtable_iter_next((hashtable_t *)&json[1], iter);
}
