int __fastcall json_object_update_existing(json_t *object, json_t *other)
{
  _BOOL4 v2; // r3
  json_t *v3; // r9
  void *v6; // r0
  const char *v7; // r4
  char *v8; // r1
  hashtable_t *v9; // r0
  void *v10; // r0
  json_t *v11; // r6

  if ( !object )
    return -1;
  v2 = other == 0;
  if ( object->type )
    v2 = 1;
  if ( v2 || other->type )
    return -1;
  v3 = other + 1;
  v6 = hashtable_iter((hashtable_t *)&other[1]);
  if ( v6 )
  {
    v7 = (const char *)hashtable_iter_key(v6);
    if ( v7 )
    {
      while ( 1 )
      {
        v11 = (json_t *)hashtable_iter_value((void *)(v7 - 16));
        if ( !v11 )
          break;
        if ( object->type || !hashtable_get((hashtable_t *)&object[1], v7) )
        {
          v8 = (char *)(v7 - 16);
          v9 = (hashtable_t *)v3;
          if ( other->type )
            return 0;
        }
        else
        {
          if ( v11->refcount != -1 )
            ++v11->refcount;
          json_object_set_new_nocheck(object, v7, v11);
          v8 = (char *)(v7 - 16);
          v9 = (hashtable_t *)v3;
          if ( other->type )
            return 0;
        }
        v10 = hashtable_iter_next(v9, v8);
        if ( v10 )
        {
          v7 = (const char *)hashtable_iter_key(v10);
          if ( v7 )
            continue;
        }
        return 0;
      }
    }
  }
  return 0;
}
