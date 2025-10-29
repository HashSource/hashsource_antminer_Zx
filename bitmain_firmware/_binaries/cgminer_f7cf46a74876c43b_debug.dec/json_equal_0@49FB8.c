// Alternative name is 'json_equal.part.2'
int __fastcall json_equal_0(json_t *json1, json_t *json2)
{
  json_type type; // r3
  hashtable_t *v6; // r9
  void *v7; // r0
  const char *v8; // r6
  json_t *v9; // r1
  void *v10; // r0
  json_t *v11; // r7
  size_t refcount; // r7
  json_type v13; // r2
  size_t v14; // r6
  json_t *v15; // r0
  json_t *v16; // r1
  bool v17; // zf

  type = json1->type;
  if ( json1->type != json2->type )
    return 0;
  if ( json1 == json2 )
    return 1;
  switch ( type )
  {
    case JSON_OBJECT:
      if ( json1[1].type != json2[1].type )
        return 0;
      v6 = (hashtable_t *)&json1[1];
      v7 = hashtable_iter((hashtable_t *)&json1[1]);
      if ( v7 )
      {
        v8 = (const char *)hashtable_iter_key(v7);
        if ( v8 )
        {
          while ( 1 )
          {
            v11 = (json_t *)hashtable_iter_value((void *)(v8 - 16));
            if ( !v11 )
              break;
            if ( json2->type )
              return 0;
            v9 = (json_t *)hashtable_get((hashtable_t *)&json2[1], v8);
            if ( !v9 || !json_equal_0(v11, v9) )
              return 0;
            if ( json1->type == JSON_OBJECT )
            {
              v10 = hashtable_iter_next(v6, (void *)(v8 - 16));
              if ( v10 )
              {
                v8 = (const char *)hashtable_iter_key(v10);
                if ( v8 )
                  continue;
              }
            }
            return 1;
          }
        }
      }
      return 1;
    case JSON_ARRAY:
      refcount = json1[1].refcount;
      if ( refcount != json2[1].refcount )
        return 0;
      if ( refcount )
      {
        v13 = JSON_ARRAY;
        v14 = 0;
        while ( 1 )
        {
          v15 = type == JSON_ARRAY && json1[1].refcount > v14 ? *(json_t **)(json1[2].type + 4 * v14) : 0;
          if ( v13 != JSON_ARRAY || json2[1].refcount <= v14 )
            break;
          v16 = *(json_t **)(json2[2].type + 4 * v14);
          v17 = v16 == 0;
          if ( v16 )
            v17 = v15 == 0;
          if ( v17 || !json_equal_0(v15, v16) )
            break;
          if ( refcount == ++v14 )
            return 1;
          type = json1->type;
          v13 = json2->type;
        }
        return 0;
      }
      return 1;
    case JSON_STRING:
      return strcmp((const char *)json1[1].type, (const char *)json2[1].type) == 0;
    case JSON_INTEGER:
      return *(_QWORD *)&json1[1] == *(_QWORD *)&json2[1];
  }
  if ( type != JSON_REAL )
    return 0;
  return *(double *)&json1[1] == *(double *)&json2[1];
}
