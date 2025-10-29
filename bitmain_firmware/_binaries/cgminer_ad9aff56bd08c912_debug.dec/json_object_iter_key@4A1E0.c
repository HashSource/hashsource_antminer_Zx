const char *__fastcall json_object_iter_key(void *iter)
{
  if ( iter )
    return (const char *)hashtable_iter_key(iter);
  return (const char *)iter;
}
