int __fastcall json_array_clear(json_t *json)
{
  size_t refcount; // r2
  size_t i; // r4
  json_t *v4; // r0
  size_t v5; // r3
  bool v6; // zf
  size_t v7; // r3

  if ( !json )
    return -1;
  if ( json->type != JSON_ARRAY )
    return -1;
  refcount = json[1].refcount;
  if ( refcount )
  {
    for ( i = 0; i < refcount; ++i )
    {
      v4 = *(json_t **)(json[2].type + 4 * i);
      if ( v4 )
      {
        v5 = v4->refcount;
        v6 = v5 == -1;
        v7 = v5 - 1;
        if ( !v6 )
        {
          v4->refcount = v7;
          if ( !v7 )
          {
            json_delete(v4);
            refcount = json[1].refcount;
          }
        }
      }
    }
  }
  json[1].refcount = 0;
  return 0;
}
