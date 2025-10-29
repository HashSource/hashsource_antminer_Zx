int __fastcall hashtable_set(hashtable_t *hashtable, const char *key, size_t serial, json_t *value)
{
  size_t v6; // r1
  hashtable_bucket *buckets; // r10
  int v9; // r3
  size_t v10; // r4
  const char *v11; // r2
  size_t v12; // r0
  int v13; // t1
  bucket_t *v14; // r10
  pair_t *pair; // r0
  pair_t *v16; // r6
  json_t *v17; // r0
  size_t refcount; // r3
  size_t v19; // r3
  size_t v21; // r0
  _DWORD *v22; // r0
  _DWORD *v23; // r6
  char *v24; // r0
  hashtable_t *first; // r2
  hashtable_list *v26; // r3
  size_t v27; // r3
  size_t v28; // r11
  hashtable_bucket *v29; // r0
  hashtable_list *p_list; // r9
  hashtable_bucket *v31; // r0
  hashtable_bucket *v32; // r2
  hashtable_list *next; // r4
  int v34; // r1
  hashtable_list v35; // r2
  hashtable_bucket *v36; // r1
  hashtable_list *v37; // r0
  size_t num_buckets; // [sp+4h] [bp-8h]

  v6 = primes[hashtable->num_buckets];
  buckets = hashtable->buckets;
  if ( hashtable->size >= v6 )
  {
    jsonp_free(hashtable->buckets);
    v27 = hashtable->num_buckets + 1;
    v28 = primes[v27];
    hashtable->num_buckets = v27;
    v29 = (hashtable_bucket *)jsonp_malloc(8 * v28);
    buckets = v29;
    hashtable->buckets = v29;
    if ( !v29 )
      return -1;
    p_list = &hashtable->list;
    v6 = primes[hashtable->num_buckets];
    num_buckets = hashtable->num_buckets;
    if ( v6 )
    {
      v31 = &v29[v6];
      v32 = buckets;
      do
      {
        v32->last = p_list;
        v32->first = p_list;
        ++v32;
      }
      while ( v31 != v32 );
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
          v34 = (unsigned int)next[-1].next % v28;
          v35.next = buckets[v34].first;
          v36 = &buckets[v34];
          v37 = next->next;
          if ( v35.next == p_list && p_list == v36->last )
            break;
          v35.prev = v35.next->prev;
          *next = v35;
          v35.next->prev->next = next;
          v35.next->prev = next;
          v36->first = next;
          next = v37;
          if ( v37 == p_list )
            goto LABEL_25;
        }
        next->prev = hashtable->list.prev;
        next->next = p_list;
        hashtable->list.prev->next = next;
        hashtable->list.prev = next;
        v36->first = next;
        v36->last = next;
        next = v37;
      }
      while ( v37 != p_list );
LABEL_25:
      buckets = hashtable->buckets;
      v6 = primes[num_buckets];
    }
  }
  v9 = *(unsigned __int8 *)key;
  v10 = 5381;
  if ( *key )
  {
    v11 = key;
    v10 = 5381;
    do
    {
      v12 = v9 + 32 * v10;
      v13 = *(unsigned __int8 *)++v11;
      v9 = v13;
      v10 += v12;
    }
    while ( v13 );
  }
  v14 = &buckets[v10 % v6];
  pair = hashtable_find_pair(hashtable, v14, key, v10);
  v16 = pair;
  if ( pair )
  {
    v17 = pair->value;
    if ( v17 )
    {
      refcount = v17->refcount;
      if ( refcount != -1 )
      {
        v19 = refcount - 1;
        v17->refcount = v19;
        if ( !v19 )
          json_delete(v17);
      }
    }
    v16->value = value;
    return 0;
  }
  v21 = strlen(key);
  v22 = jsonp_malloc(v21 + 21);
  v23 = v22;
  if ( !v22 )
    return -1;
  *v22 = v10;
  v24 = (char *)(v22 + 5);
  *((_DWORD *)v24 - 1) = serial;
  strcpy(v24, key);
  first = (hashtable_t *)v14->first;
  v26 = (hashtable_list *)(v23 + 1);
  v23[2] = v23 + 1;
  v23[3] = value;
  v23[1] = v23 + 1;
  if ( first == (hashtable_t *)&hashtable->list && first == (hashtable_t *)v14->last )
  {
    v23[1] = hashtable->list.prev;
    v23[2] = first;
    hashtable->list.prev->next = v26;
    hashtable->list.prev = v26;
    v14->first = v26;
    v14->last = v26;
  }
  else
  {
    v23[1] = first->size;
    v23[2] = first;
    *(_DWORD *)(first->size + 4) = v26;
    first->size = (size_t)v26;
    v14->first = v26;
  }
  ++hashtable->size;
  return 0;
}
