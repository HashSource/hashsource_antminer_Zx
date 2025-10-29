void __fastcall hashtable_clear(hashtable_t *hashtable)
{
  int v2; // r3
  hashtable_list *p_list; // r2
  int v4; // r1
  hashtable_bucket *buckets; // r3
  hashtable_bucket *v6; // r1

  hashtable_do_clear(hashtable);
  LOWORD(v2) = -20252;
  p_list = &hashtable->list;
  HIWORD(v2) = (unsigned int)"\\u%04x\\u%04x" >> 16;
  v4 = *(_DWORD *)(v2 + 4 * hashtable->num_buckets);
  if ( v4 )
  {
    buckets = hashtable->buckets;
    v6 = &buckets[v4];
    do
    {
      buckets->last = p_list;
      buckets->first = p_list;
      ++buckets;
    }
    while ( v6 != buckets );
  }
  hashtable->list.prev = p_list;
  hashtable->list.next = p_list;
  hashtable->size = 0;
}
