int __fastcall json_object_set_new(json_t *json, const char *key, json_t *value)
{
  size_t refcount; // r3
  size_t v8; // r3

  if ( key && utf8_check_string(key, -1) )
    return json_object_set_new_nocheck(json, key, value);
  if ( value )
  {
    refcount = value->refcount;
    if ( refcount != -1 )
    {
      v8 = refcount - 1;
      value->refcount = v8;
      if ( !v8 )
        json_delete(value);
    }
  }
  return -1;
}
