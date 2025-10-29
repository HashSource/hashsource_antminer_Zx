int __fastcall hashtable_set(hashtable_t *hashtable, const char *key, size_t serial, json_t *value)
{
  int v4; // r6
  size_t v7; // r1
  hashtable_bucket *buckets; // r10
  int v10; // r3
  size_t v11; // r4
  const char *v12; // r2
  size_t v13; // r0
  int v14; // t1
  bucket_t *v15; // r10
  pair_t *pair; // r0
  pair_t *v17; // r6
  json_t *v18; // r0
  size_t refcount; // r3
  size_t v20; // r3
  size_t v22; // r0
  _DWORD *v23; // r0
  _DWORD *v24; // r6
  char *v25; // r0
  hashtable_t *first; // r2
  hashtable_list *v27; // r3
  size_t v28; // r3
  unsigned int v29; // r11
  hashtable_bucket *v30; // r0
  hashtable_list *p_list; // r9
  hashtable_bucket *v32; // r0
  hashtable_bucket *v33; // r2
  hashtable_list *next; // r4
  int v35; // r1
  hashtable_list v36; // r2
  hashtable_bucket *v37; // r1
  hashtable_list *v38; // r0
  size_t num_buckets; // [sp+4h] [bp-8h]

  LOWORD(v4) = -20252;
  HIWORD(v4) = (unsigned int)"\\u%04x\\u%04x" >> 16;
  v7 = *(_DWORD *)(v4 + 4 * hashtable->num_buckets);
  buckets = hashtable->buckets;
  if ( hashtable->size >= v7 )
  {
    jsonp_free(hashtable->buckets);
    v28 = hashtable->num_buckets + 1;
    v29 = *(_DWORD *)(v4 + 4 * v28);
    hashtable->num_buckets = v28;
    v30 = (hashtable_bucket *)jsonp_malloc(8 * v29);
    buckets = v30;
    hashtable->buckets = v30;
    if ( !v30 )
      return -1;
    p_list = &hashtable->list;
    v7 = *(_DWORD *)(v4 + 4 * hashtable->num_buckets);
    num_buckets = hashtable->num_buckets;
    if ( v7 )
    {
      v32 = &v30[v7];
      v33 = buckets;
      do
      {
        v33->last = p_list;
        v33->first = p_list;
        ++v33;
      }
      while ( v32 != v33 );
    }
    next = hashtable->list.next;
    hashtable->list.prev = p_list;
    hashtable->list.next = p_list;
    if ( next != p_list )
    {
      do
      {
        while ( 1 )
        {
          v35 = (unsigned int)next[-1].next % v29;
          v36.next = buckets[v35].first;
          v37 = &buckets[v35];
          v38 = next->next;
          if ( v36.next == p_list && p_list == v37->last )
            break;
          v36.prev = v36.next->prev;
          *next = v36;
          v36.next->prev->next = next;
          v36.next->prev = next;
          v37->first = next;
          next = v38;
          if ( v38 == p_list )
            goto LABEL_25;
        }
        next->prev = hashtable->list.prev;
        next->next = p_list;
        hashtable->list.prev->next = next;
        hashtable->list.prev = next;
        v37->first = next;
        v37->last = next;
        next = v38;
      }
      while ( v38 != p_list );
LABEL_25:
      buckets = hashtable->buckets;
      v7 = *(_DWORD *)(v4 + 4 * num_buckets);
    }
  }
  v10 = *(unsigned __int8 *)key;
  v11 = 5381;
  if ( *key )
  {
    v12 = key;
    v11 = 5381;
    do
    {
      v13 = v10 + 32 * v11;
      v14 = *(unsigned __int8 *)++v12;
      v10 = v14;
      v11 += v13;
    }
    while ( v14 );
  }
  v15 = &buckets[v11 % v7];
  pair = hashtable_find_pair(hashtable, v15, key, v11);
  v17 = pair;
  if ( pair )
  {
    v18 = pair->value;
    if ( v18 )
    {
      refcount = v18->refcount;
      if ( refcount != -1 )
      {
        v20 = refcount - 1;
        v18->refcount = v20;
        if ( !v20 )
          json_delete(v18);
      }
    }
    v17->value = value;
    return 0;
  }
  v22 = strlen(key);
  v23 = jsonp_malloc(v22 + 21);
  v24 = v23;
  if ( !v23 )
    return -1;
  *v23 = v11;
  v25 = (char *)(v23 + 5);
  *((_DWORD *)v25 - 1) = serial;
  strcpy(v25, key);
  first = (hashtable_t *)v15->first;
  v27 = (hashtable_list *)(v24 + 1);
  v24[2] = v24 + 1;
  v24[3] = value;
  v24[1] = v24 + 1;
  if ( first == (hashtable_t *)&hashtable->list && first == (hashtable_t *)v15->last )
  {
    v24[1] = hashtable->list.prev;
    v24[2] = first;
    hashtable->list.prev->next = v27;
    hashtable->list.prev = v27;
    v15->first = v27;
    v15->last = v27;
  }
  else
  {
    v24[1] = first->size;
    v24[2] = first;
    *(_DWORD *)(first->size + 4) = v27;
    first->size = (size_t)v27;
    v15->first = v27;
  }
  ++hashtable->size;
  return 0;
}
