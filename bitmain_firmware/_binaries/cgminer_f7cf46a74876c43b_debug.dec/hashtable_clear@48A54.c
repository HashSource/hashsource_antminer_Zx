void __fastcall hashtable_clear(hashtable_t *hashtable)
{
  hashtable_list *p_list; // r2
  size_t v3; // r1
  hashtable_bucket *buckets; // r3
  hashtable_bucket *v5; // r1

  hashtable_do_clear(hashtable);
  p_list = &hashtable->list;
  v3 = primes[hashtable->num_buckets];
  if ( v3 )
  {
    buckets = hashtable->buckets;
    v5 = &buckets[v3];
    do
    {
      buckets->last = p_list;
      buckets->first = p_list;
      ++buckets;
    }
    while ( v5 != buckets );
  }
  hashtable->list.prev = p_list;
  hashtable->list.next = p_list;
  hashtable->size = 0;
}
