int __fastcall json_array_insert_new(json_t *json, size_t index, json_t *value)
{
  _BOOL4 v6; // r2
  json_t **v7; // r8
  json_t **type; // r0
  size_t v9; // r5
  size_t v11; // r3
  size_t refcount; // r3
  size_t v13; // r3

  if ( !value )
    return -1;
  if ( json
    && (json->type != JSON_ARRAY ? (v6 = 1) : (v6 = value == json),
        !v6 && json[1].refcount >= index && (v7 = json_array_grow((json_array_t *)json, 1u, 0)) != 0) )
  {
    type = (json_t **)json[2].type;
    v9 = index + 1;
    if ( type == v7 )
    {
      memmove(&type[v9], &v7[v9 - 1], 4 * (json[1].refcount - index));
    }
    else
    {
      memcpy(type, v7, v9 * 4 - 4);
      memcpy((void *)(json[2].type + v9 * 4), &v7[v9 - 1], 4 * (json[1].refcount - index));
      jsonp_free(v7);
    }
    v11 = json[1].refcount + 1;
    *(_DWORD *)(json[2].type + v9 * 4 - 4) = value;
    json[1].refcount = v11;
    return 0;
  }
  else
  {
    refcount = value->refcount;
    if ( refcount != -1 )
    {
      v13 = refcount - 1;
      value->refcount = v13;
      if ( !v13 )
        json_delete(value);
    }
    return -1;
  }
}
