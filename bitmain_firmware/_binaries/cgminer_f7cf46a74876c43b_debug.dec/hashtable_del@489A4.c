int __fastcall hashtable_del(hashtable_t *hashtable, const char *key)
{
  const char *v2; // r6
  int v3; // r3
  size_t v5; // r4
  size_t v6; // r0
  int v7; // t1
  hashtable_bucket *buckets; // r7
  const char *v9; // r2
  size_t v10; // r8
  bucket_t *v11; // r6
  pair_t *pair; // r0
  pair_t *v13; // r4
  hashtable_list *p_list; // r2
  hashtable_list list; // kr00_8
  hashtable_list *last; // r12
  json_t *value; // r0
  size_t refcount; // r3
  size_t v19; // r3
  bool v21; // zf

  v2 = key;
  v3 = *(unsigned __int8 *)key;
  v5 = 5381;
  if ( *key )
  {
    v5 = 5381;
    do
    {
      v6 = v3 + 32 * v5;
      v7 = *(unsigned __int8 *)++key;
      v3 = v7;
      v5 += v6;
    }
    while ( v7 );
  }
  buckets = hashtable->buckets;
  v9 = v2;
  v10 = v5 % primes[hashtable->num_buckets];
  v11 = &buckets[v10];
  pair = hashtable_find_pair(hashtable, v11, v9, v5);
  v13 = pair;
  if ( !pair )
    return -1;
  p_list = &pair->list;
  list = pair->list;
  last = v11->last;
  if ( &pair->list == buckets[v10].first )
  {
    v21 = p_list == last;
    if ( p_list == last )
      p_list = &hashtable->list;
    else
      buckets[v10].first = list.next;
    if ( v21 )
    {
      v11->last = p_list;
      buckets[v10].first = p_list;
    }
  }
  else if ( p_list == last )
  {
    v11->last = list.prev;
  }
  value = pair->value;
  list.prev->next = list.next;
  v13->list.next->prev = list.prev;
  if ( value )
  {
    refcount = value->refcount;
    if ( refcount != -1 )
    {
      v19 = refcount - 1;
      value->refcount = v19;
      if ( !v19 )
        json_delete(value);
    }
  }
  jsonp_free(v13);
  --hashtable->size;
  return 0;
}
