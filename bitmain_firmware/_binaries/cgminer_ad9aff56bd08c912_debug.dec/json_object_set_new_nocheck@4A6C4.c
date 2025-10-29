int __fastcall json_object_set_new_nocheck(json_t *json, const char *key, json_t *value)
{
  bool v3; // zf
  _BOOL4 v5; // r3
  size_t v6; // r2
  int result; // r0
  size_t refcount; // r3
  size_t v9; // r3

  if ( !value )
    return -1;
  v3 = json == 0;
  if ( json )
    v3 = key == 0;
  if ( v3 )
    goto LABEL_9;
  v5 = value == json;
  if ( json->type )
    v5 = 1;
  if ( v5
    || (v6 = json[3].refcount,
        json[3].refcount = v6 + 1,
        (result = hashtable_set((hashtable_t *)&json[1], key, v6, value)) != 0) )
  {
LABEL_9:
    refcount = value->refcount;
    if ( refcount != -1 )
    {
      v9 = refcount - 1;
      value->refcount = v9;
      if ( !v9 )
        json_delete(value);
    }
    return -1;
  }
  return result;
}
