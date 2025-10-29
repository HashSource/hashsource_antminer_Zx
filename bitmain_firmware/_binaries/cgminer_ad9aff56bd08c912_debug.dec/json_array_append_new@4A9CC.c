int __fastcall json_array_append_new(json_t *json, json_t *value)
{
  _BOOL4 v4; // r5
  size_t refcount; // r3
  size_t v7; // r3
  size_t v8; // r3

  if ( !value )
    return -1;
  if ( !json )
    goto LABEL_8;
  v4 = value == json;
  if ( json->type != JSON_ARRAY )
    v4 = 1;
  if ( !v4 && json_array_grow((json_array_t *)json, 1u, 1) )
  {
    refcount = json[1].refcount;
    *(_DWORD *)(json[2].type + 4 * refcount) = value;
    json[1].refcount = refcount + 1;
    return 0;
  }
  else
  {
LABEL_8:
    v7 = value->refcount;
    if ( v7 != -1 )
    {
      v8 = v7 - 1;
      value->refcount = v8;
      if ( !v8 )
        json_delete(value);
    }
    return -1;
  }
}
