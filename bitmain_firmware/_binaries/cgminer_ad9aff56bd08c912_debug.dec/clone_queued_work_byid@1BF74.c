work *__fastcall clone_queued_work_byid(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r7
  const char *v5; // r2
  int v6; // r3
  work *readers; // r4
  const work *next; // r5
  const char *v9; // r2
  int v10; // r3

  v2 = a1 + 10;
  if ( pthread_rwlock_rdlock(a1 + 10) )
    rd_lock((pthread_rwlock_t *)(&_func___16796.__align + 7), (const char *)0x22DC, v5, v6);
  readers = (work *)a1[11].__readers;
  if ( readers )
  {
    next = (const work *)readers->hh.next;
    if ( a2 == readers->id )
    {
      next = readers;
    }
    else
    {
      readers = (work *)readers->hh.next;
      if ( !next )
        goto LABEL_9;
      readers = (work *)next->hh.next;
      while ( a2 != next->id )
      {
        if ( !readers )
          goto LABEL_9;
        next = readers;
        readers = (work *)readers->hh.next;
      }
    }
    readers = make_work();
    copy_work(readers, next, 0);
  }
LABEL_9:
  if ( pthread_rwlock_unlock(v2) )
    rw_unlock((pthread_rwlock_t *)(&_func___16796.__align + 7), (const char *)0x22E0, v9, v10);
  selective_yield();
  return readers;
}
