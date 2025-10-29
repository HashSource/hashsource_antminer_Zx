int __fastcall json_object_update_missing(json_t *object, json_t *other)
{
  _BOOL4 v2; // r3
  hashtable_t *v3; // r9
  void *v6; // r0
  const char *v7; // r4
  size_t refcount; // r3
  void *v9; // r0
  json_t *v10; // r5

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
    v7 = (const char *)hashtable_iter_key(v6);
    if ( v7 )
    {
      while ( 1 )
      {
        v10 = (json_t *)hashtable_iter_value((void *)(v7 - 16));
        if ( !v10 )
          break;
        if ( object->type || !hashtable_get((hashtable_t *)&object[1], v7) )
        {
          refcount = v10->refcount;
          if ( refcount != -1 )
            v10->refcount = refcount + 1;
          json_object_set_new_nocheck(object, v7, v10);
          if ( other->type )
            return 0;
        }
        else if ( other->type )
        {
          return 0;
        }
        v9 = hashtable_iter_next(v3, (void *)(v7 - 16));
        if ( v9 )
        {
          v7 = (const char *)hashtable_iter_key(v9);
          if ( v7 )
            continue;
        }
        return 0;
      }
    }
  }
  return 0;
}
