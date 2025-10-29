// local variable allocation has failed, the output may be wrong!
json_t *__fastcall json_deep_copy(const json_t *json)
{
  json_type type; // r3
  json_t *v3; // r6
  void *i; // r4
  const char *v5; // r7
  const json_t *v6; // r0
  json_t *v7; // r0
  size_t refcount; // r3
  size_t j; // r4
  const json_t *v11; // r0
  json_t *v12; // r0

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
        for ( i = hashtable_iter((hashtable_t *)&json[1]); i; i = hashtable_iter_next((hashtable_t *)&json[1], i) )
        {
          v5 = (const char *)hashtable_iter_key(i);
          v6 = (const json_t *)hashtable_iter_value(i);
          v7 = json_deep_copy(v6);
          json_object_set_new_nocheck(v3, v5, v7);
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
              v11 = 0;
              if ( refcount > j )
                v11 = *(const json_t **)(json[2].type + 4 * j);
              v12 = json_deep_copy(v11);
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
      return (json_t *)json;
    return 0;
  }
  return json_real(*(double *)&json);
}
