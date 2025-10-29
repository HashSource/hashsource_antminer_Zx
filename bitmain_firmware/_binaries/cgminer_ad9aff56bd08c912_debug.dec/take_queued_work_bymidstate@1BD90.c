work *__fastcall take_queued_work_bymidstate(cgpu_info *a1, char *a2, size_t a3, char *a4, int offset, size_t datalen)
{
  pthread_rwlock_t *p_qlock; // r6
  const char *v11; // r2
  int v12; // r3
  work *work_bymidstate; // r5
  const char *v14; // r2
  int v15; // r3

  p_qlock = &a1->qlock;
  if ( pthread_rwlock_wrlock(&a1->qlock) )
    wr_lock((pthread_rwlock_t *)(&_func___16717.__align + 7), (const char *)0x2316, v11, v12);
  work_bymidstate = _find_work_bymidstate(a1->queued_work, a2, a3, a4, offset, datalen);
  if ( work_bymidstate )
    _work_completed(a1, work_bymidstate);
  if ( pthread_rwlock_unlock(p_qlock) )
    rw_unlock((pthread_rwlock_t *)(&_func___16717.__align + 7), (const char *)0x231A, v14, v15);
  selective_yield();
  return work_bymidstate;
}
