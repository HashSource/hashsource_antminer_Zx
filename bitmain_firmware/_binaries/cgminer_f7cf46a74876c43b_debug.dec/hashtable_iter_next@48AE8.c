void *__fastcall hashtable_iter_next(hashtable_t *hashtable, void *iter)
{
  if ( *((hashtable_t **)iter + 1) == (hashtable_t *)&hashtable->list )
    return 0;
  else
    return (void *)*((_DWORD *)iter + 1);
}
