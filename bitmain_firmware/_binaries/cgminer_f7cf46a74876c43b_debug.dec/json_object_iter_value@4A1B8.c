json_t *__fastcall json_object_iter_value(void *iter)
{
  if ( iter )
    return (json_t *)hashtable_iter_value(iter);
  return (json_t *)iter;
}
