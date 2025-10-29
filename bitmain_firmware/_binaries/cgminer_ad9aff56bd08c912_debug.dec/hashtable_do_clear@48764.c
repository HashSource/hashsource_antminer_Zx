void __fastcall hashtable_do_clear(hashtable_t *hashtable)
{
  hashtable_list *p_list; // r6
  hashtable_t *next; // r4
  json_t *num_buckets; // r0
  hashtable_list **p_next; // r5
  size_t refcount; // r3
  bool v6; // zf
  size_t v7; // r3

  p_list = &hashtable->list;
  next = (hashtable_t *)hashtable->list.next;
  if ( next != (hashtable_t *)&hashtable->list )
  {
    do
    {
      num_buckets = (json_t *)next->num_buckets;
      p_next = &next[-1].list.next;
      next = (hashtable_t *)next->buckets;
      if ( num_buckets )
      {
        refcount = num_buckets->refcount;
        v6 = refcount == -1;
        v7 = refcount - 1;
        if ( !v6 )
        {
          num_buckets->refcount = v7;
          if ( !v7 )
            json_delete(num_buckets);
        }
      }
      jsonp_free(p_next);
    }
    while ( next != (hashtable_t *)p_list );
  }
}
