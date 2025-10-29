int __fastcall json_array_set_new(json_t *json, size_t index, json_t *value)
{
  _BOOL4 v5; // r3
  json_type type; // r3
  size_t v7; // r6
  json_t *v8; // r0
  json_t **v9; // r3
  size_t v10; // r2
  size_t v11; // r2
  size_t refcount; // r3
  size_t v14; // r3

  if ( !value )
    return -1;
  if ( !json )
    goto LABEL_12;
  v5 = value == json;
  if ( json->type != JSON_ARRAY )
    v5 = 1;
  if ( v5 || json[1].refcount <= index )
  {
LABEL_12:
    refcount = value->refcount;
    if ( refcount != -1 )
    {
      v14 = refcount - 1;
      value->refcount = v14;
      if ( !v14 )
        json_delete(value);
    }
    return -1;
  }
  else
  {
    type = json[2].type;
    v7 = 4 * index;
    v8 = *(json_t **)(type + 4 * index);
    v9 = (json_t **)(type + 4 * index);
    if ( !v8 || (v10 = v8->refcount, v10 == -1) || (v11 = v10 - 1, (v8->refcount = v11) != 0) )
    {
      *v9 = value;
      return 0;
    }
    else
    {
      json_delete(v8);
      *(_DWORD *)(json[2].type + v7) = value;
      return 0;
    }
  }
}
