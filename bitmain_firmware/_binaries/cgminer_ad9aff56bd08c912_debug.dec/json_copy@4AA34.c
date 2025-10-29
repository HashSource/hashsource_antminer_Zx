// local variable allocation has failed, the output may be wrong!
json_t *__fastcall json_copy(json_t *json)
{
  json_type type; // r3
  json_t *v3; // r8
  void *i; // r0
  const char *v6; // r0
  const char *v7; // r6
  char *v8; // r7
  json_t *v9; // r0
  size_t refcount; // r3
  size_t j; // r4
  json_t *v12; // r1

  if ( !json )
    return 0;
  type = json->type;
  if ( json->type == JSON_OBJECT )
  {
    v3 = (json_t *)json_object();
    if ( v3 )
    {
      if ( json->type == JSON_OBJECT )
      {
        for ( i = hashtable_iter((hashtable_t *)&json[1]); i; i = hashtable_iter_next((hashtable_t *)&json[1], v8) )
        {
          v6 = (const char *)hashtable_iter_key(i);
          v7 = v6;
          if ( !v6 )
            break;
          v8 = (char *)(v6 - 16);
          v9 = (json_t *)hashtable_iter_value((void *)(v6 - 16));
          if ( !v9 )
            break;
          if ( v9->refcount != -1 )
            ++v9->refcount;
          json_object_set_new_nocheck(v3, v7, v9);
          if ( json->type )
            break;
        }
      }
      return v3;
    }
    return 0;
  }
  switch ( type )
  {
    case JSON_ARRAY:
      v3 = json_array();
      if ( v3 )
      {
        if ( json->type == JSON_ARRAY )
        {
          refcount = json[1].refcount;
          if ( refcount )
          {
            for ( j = 0; j < refcount; ++j )
            {
              v12 = 0;
              if ( j < refcount )
              {
                v12 = *(json_t **)(json[2].type + 4 * j);
                if ( v12 )
                {
                  if ( v12->refcount != -1 )
                    ++v12->refcount;
                }
              }
              json_array_append_new(v3, v12);
              if ( json->type != JSON_ARRAY )
                break;
              refcount = json[1].refcount;
            }
          }
        }
        return v3;
      }
      return 0;
    case JSON_STRING:
      return json_string_nocheck((const char *)json[1].type);
    case JSON_INTEGER:
      return json_integer_copy(json);
  }
  if ( type != JSON_REAL )
  {
    if ( (unsigned int)(type - 5) <= 2 )
      return json;
    return 0;
  }
  return json_real(*(double *)&json);
}
