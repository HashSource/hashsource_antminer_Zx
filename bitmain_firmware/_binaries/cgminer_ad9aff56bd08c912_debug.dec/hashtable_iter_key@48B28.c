void *__fastcall hashtable_iter_key(void *iter)
{
  return (char *)iter + 16;
}
