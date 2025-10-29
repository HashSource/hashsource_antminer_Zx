void *__fastcall hashtable_iter(hashtable_t *hashtable)
{
  if ( hashtable->list.next == &hashtable->list )
    return 0;
  else
    return hashtable->list.next;
}
