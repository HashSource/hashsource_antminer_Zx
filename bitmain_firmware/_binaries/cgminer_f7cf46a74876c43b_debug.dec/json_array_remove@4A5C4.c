int __fastcall json_array_remove(json_t *json, size_t index)
{
  size_t refcount; // r2
  size_t v5; // r6
  json_t *v6; // r0
  size_t v7; // r3
  size_t v8; // r3

  if ( !json )
    return -1;
  if ( json->type != JSON_ARRAY )
    return -1;
  refcount = json[1].refcount;
  if ( refcount <= index )
    return -1;
  v5 = 4 * index;
  v6 = *(json_t **)(json[2].type + 4 * index);
  if ( v6 )
  {
    v7 = v6->refcount;
    if ( v7 != -1 )
    {
      v8 = v7 - 1;
      v6->refcount = v8;
      if ( !v8 )
      {
        json_delete(v6);
        refcount = json[1].refcount;
      }
    }
  }
  if ( refcount - 1 > index )
  {
    memmove((void *)(json[2].type + v5), (const void *)(v5 + 4 + json[2].type), 4 * (refcount + ~index));
    --json[1].refcount;
  }
  else
  {
    json[1].refcount = refcount - 1;
  }
  return 0;
}
