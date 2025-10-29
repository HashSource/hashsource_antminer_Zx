void *__fastcall hashtable_iter_value(void *iter)
{
  return (void *)*((_DWORD *)iter + 2);
}
