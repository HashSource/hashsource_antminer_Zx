void __fastcall hashtable_close(hashtable_t *hashtable)
{
  hashtable_do_clear(hashtable);
  jsonp_free(hashtable->buckets);
}
