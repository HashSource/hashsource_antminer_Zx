work *__fastcall find_queued_work_bymidstate(int a1, char *a2, size_t a3, char *a4, int offset, size_t datalen)
{
  pthread_rwlock_t *v6; // r4
  const char *v11; // r2
  int v12; // r3
  work *work_bymidstate; // r5
  const char *v14; // r2
  int v15; // r3

  v6 = (pthread_rwlock_t *)(a1 + 320);
  if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 320)) )
    rd_lock((pthread_rwlock_t *)(&_func___16774.__align + 6), (const char *)0x22A5, v11, v12);
  work_bymidstate = _find_work_bymidstate(*(work **)(a1 + 352), a2, a3, a4, offset, datalen);
  if ( pthread_rwlock_unlock(v6) )
    rw_unlock((pthread_rwlock_t *)(&_func___16774.__align + 6), (const char *)0x22A7, v14, v15);
  selective_yield();
  return work_bymidstate;
}
