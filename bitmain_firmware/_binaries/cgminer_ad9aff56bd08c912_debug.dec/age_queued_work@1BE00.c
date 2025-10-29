int __fastcall age_queued_work(pthread_rwlock_t *a1)
{
  const char *v2; // r2
  int v3; // r3
  timeval *readers; // r5
  timeval *i; // r4
  const char *v6; // r2
  int v7; // r3
  timeval v9; // [sp+0h] [bp-8h] BYREF

  cgtime(&v9);
  if ( pthread_rwlock_wrlock(a1 + 10) )
    wr_lock((pthread_rwlock_t *)&_func___16796, (const char *)0x22F6, v2, v3);
  readers = (timeval *)a1[11].__readers;
  if ( readers )
  {
    for ( i = (timeval *)readers[230].tv_sec; ; i = (timeval *)i[230].tv_sec )
    {
      tdiff(&v9, readers + 239);
      if ( !i )
        break;
      readers = i;
    }
  }
  if ( pthread_rwlock_unlock(a1 + 10) )
    rw_unlock((pthread_rwlock_t *)&_func___16796, (const char *)0x2300, v6, v7);
  selective_yield();
  return 0;
}
