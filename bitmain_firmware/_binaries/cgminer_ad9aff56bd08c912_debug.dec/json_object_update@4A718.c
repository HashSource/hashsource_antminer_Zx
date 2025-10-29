int __fastcall json_object_update(json_t *object, json_t *other)
{
  _BOOL4 v2; // r3
  hashtable_t *v3; // r9
  void *v6; // r0
  const char *v8; // r0
  const char *v9; // r5
  char *v10; // r6
  json_t *v11; // r0

  if ( !object )
    return -1;
  v2 = other == 0;
  if ( object->type )
    v2 = 1;
  if ( v2 || other->type )
    return -1;
  v3 = (hashtable_t *)&other[1];
  v6 = hashtable_iter((hashtable_t *)&other[1]);
  if ( v6 )
  {
    while ( 1 )
    {
      v8 = (const char *)hashtable_iter_key(v6);
      v9 = v8;
      if ( !v8 )
        break;
      v10 = (char *)(v8 - 16);
      v11 = (json_t *)hashtable_iter_value((void *)(v8 - 16));
      if ( !v11 )
        break;
      if ( v11->refcount != -1 )
        ++v11->refcount;
      if ( json_object_set_new_nocheck(object, v9, v11) )
        return -1;
      if ( other->type == JSON_OBJECT )
      {
        v6 = hashtable_iter_next(v3, v10);
        if ( v6 )
          continue;
      }
      return 0;
    }
  }
  return 0;
}
