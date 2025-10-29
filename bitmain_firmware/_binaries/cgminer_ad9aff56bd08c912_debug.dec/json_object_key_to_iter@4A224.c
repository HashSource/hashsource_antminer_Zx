void *__fastcall json_object_key_to_iter(const char *key)
{
  if ( key )
    key -= 16;
  return (void *)key;
}
