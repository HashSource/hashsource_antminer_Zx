unsigned int __fastcall find_queued_work_byid(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r6
  const char *v5; // r2
  int v6; // r3
  unsigned int readers; // r4
  unsigned int v8; // r3
  const char *v9; // r2
  int v10; // r3

  v2 = a1 + 10;
  if ( pthread_rwlock_rdlock(a1 + 10) )
    rd_lock((pthread_rwlock_t *)&_func___16774, (const char *)0x22D1, v5, v6);
  readers = a1[11].__readers;
  if ( readers )
  {
    v8 = *(_DWORD *)(readers + 1840);
    if ( a2 != *(_DWORD *)(readers + 1828) )
    {
      if ( v8 )
      {
        readers = *(_DWORD *)(v8 + 1840);
        while ( a2 != *(_DWORD *)(v8 + 1828) )
        {
          if ( !readers )
            goto LABEL_9;
          v8 = readers;
          readers = *(_DWORD *)(readers + 1840);
        }
      }
      readers = v8;
    }
  }
LABEL_9:
  if ( pthread_rwlock_unlock(v2) )
    rw_unlock((pthread_rwlock_t *)&_func___16774, (const char *)0x22D3, v9, v10);
  selective_yield();
  return readers;
}
