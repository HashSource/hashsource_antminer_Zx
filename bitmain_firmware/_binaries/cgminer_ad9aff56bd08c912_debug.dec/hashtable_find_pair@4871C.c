pair_t *__fastcall hashtable_find_pair(hashtable_t *hashtable, bucket_t *bucket, const char *key, size_t hash)
{
  hashtable_list *first; // r4

  first = bucket->first;
  if ( bucket->first == &hashtable->list && first == bucket->last )
    return 0;
  while ( first[-1].next != (hashtable_list *)hash || strcmp((const char *)&first[2], key) )
  {
    if ( bucket->last == first )
      return 0;
    first = first->next;
  }
  return (pair_t *)&first[-1].next;
}
