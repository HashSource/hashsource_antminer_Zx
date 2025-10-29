int __fastcall json_array_extend(json_t *json, json_t *other_json)
{
  _BOOL4 v2; // r3
  char *type; // r1
  size_t refcount; // r2
  char *v7; // r5
  int v8; // r4
  int v9; // t1

  if ( !json )
    return -1;
  v2 = other_json == 0;
  if ( json->type != JSON_ARRAY )
    v2 = 1;
  if ( v2 || other_json->type != JSON_ARRAY || !json_array_grow((json_array_t *)json, other_json[1].refcount, 1) )
    return -1;
  type = (char *)other_json[2].type;
  refcount = other_json[1].refcount;
  if ( refcount )
  {
    refcount *= 4;
    v7 = (char *)other_json[2].type;
    do
    {
      v9 = *(_DWORD *)v7;
      v7 += 4;
      v8 = v9;
      if ( v9 )
      {
        if ( *(_DWORD *)(v8 + 4) != -1 )
          ++*(_DWORD *)(v8 + 4);
      }
    }
    while ( &type[refcount] != v7 );
  }
  memcpy((void *)(json[2].type + 4 * json[1].refcount), type, refcount);
  json[1].refcount += other_json[1].refcount;
  return 0;
}
