int __fastcall hashtable_init(hashtable_t *hashtable)
{
  hashtable_bucket *v2; // r0
  size_t num_buckets; // r1
  hashtable_list *p_list; // r3
  size_t v5; // r2
  hashtable_bucket *v6; // r2

  hashtable->size = 0;
  hashtable->num_buckets = 0;
  v2 = (hashtable_bucket *)jsonp_malloc(0x28u);
  hashtable->buckets = v2;
  if ( !v2 )
    return -1;
  num_buckets = hashtable->num_buckets;
  p_list = &hashtable->list;
  hashtable->list.next = &hashtable->list;
  v5 = primes[num_buckets];
  hashtable->list.prev = &hashtable->list;
  if ( v5 )
  {
    v6 = &v2[v5];
    do
    {
      v2->last = p_list;
      v2->first = p_list;
      ++v2;
    }
    while ( v2 != v6 );
  }
  return 0;
}
