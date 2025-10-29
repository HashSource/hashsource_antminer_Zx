void __fastcall json_delete(json_t *json)
{
  json_t *v1; // r4
  json_type type; // r3
  __int64 v3; // kr00_8
  unsigned int v4; // r5
  json_t *v5; // r0
  size_t refcount; // r3
  bool v7; // zf
  size_t v8; // r3

  if ( !json )
    return;
  v1 = json;
  type = json->type;
  if ( json->type == JSON_OBJECT )
  {
    hashtable_close((hashtable_t *)&json[1]);
    json = v1;
    goto LABEL_8;
  }
  if ( type == JSON_ARRAY )
  {
    v3 = *(_QWORD *)&json[1].refcount;
    if ( (_DWORD)v3 )
    {
      v4 = 0;
      do
      {
        v5 = *(json_t **)(HIDWORD(v3) + 4 * v4++);
        if ( v5 )
        {
          refcount = v5->refcount;
          v7 = refcount == -1;
          v8 = refcount - 1;
          if ( !v7 )
          {
            v5->refcount = v8;
            if ( !v8 )
            {
              json_delete(v5);
              v3 = *(_QWORD *)&v1[1].refcount;
            }
          }
        }
      }
      while ( v4 < (unsigned int)v3 );
    }
    jsonp_free((void *)HIDWORD(v3));
    jsonp_free(v1);
    return;
  }
  if ( type == JSON_STRING )
  {
    jsonp_free((void *)json[1].type);
    jsonp_free(v1);
    return;
  }
  if ( (unsigned int)(type - 3) <= 1 )
LABEL_8:
    jsonp_free(json);
}
