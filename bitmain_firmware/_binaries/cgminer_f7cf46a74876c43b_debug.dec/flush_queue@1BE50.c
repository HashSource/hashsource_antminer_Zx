void __fastcall flush_queue(pthread_rwlock_t *a1)
{
  pthread_rwlock_t *v1; // r5
  pthread_rwlock_t *v3; // r0
  work *writers; // r5
  const char *v5; // r2
  int v6; // r3
  cgpu_info *v7; // r0

  if ( a1 )
  {
    v1 = a1 + 10;
    if ( !pthread_rwlock_trywrlock(a1 + 10) )
    {
      v3 = v1;
      writers = (work *)a1[11].__writers;
      a1[11].__writers = 0;
      if ( pthread_rwlock_unlock(v3) )
        rw_unlock((pthread_rwlock_t *)(&_func___16796.__align + 4), (const char *)0x232C, v5, v6);
      selective_yield();
      if ( writers )
      {
        clean_work(writers);
        free(writers);
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          flush_queue_0(v7);
      }
    }
  }
}
