void *__fastcall json_object_iter(json_t *json)
{
  if ( !json || json->type )
    return 0;
  else
    return hashtable_iter((hashtable_t *)&json[1]);
}
