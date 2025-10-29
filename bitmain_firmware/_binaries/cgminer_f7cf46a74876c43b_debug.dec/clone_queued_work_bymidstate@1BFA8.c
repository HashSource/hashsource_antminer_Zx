work *__fastcall clone_queued_work_bymidstate(
        cgpu_info *cgpu,
        char *midstate,
        size_t midstatelen,
        char *data,
        int offset,
        size_t datalen)
{
  pthread_rwlock_t *p_qlock; // r4
  const char *v11; // r2
  int v12; // r3
  work *work_bymidstate; // r5
  work *work; // r7
  const char *v15; // r2
  int v16; // r3

  p_qlock = &cgpu->qlock;
  if ( pthread_rwlock_rdlock(&cgpu->qlock) )
    rd_lock((pthread_rwlock_t *)&_func___16758, (const char *)0x22B0, v11, v12);
  work_bymidstate = _find_work_bymidstate(cgpu->queued_work, midstate, midstatelen, data, offset, datalen);
  if ( work_bymidstate )
  {
    work = make_work();
    copy_work(work, work_bymidstate, 0);
  }
  else
  {
    work = 0;
  }
  if ( pthread_rwlock_unlock(p_qlock) )
    rw_unlock((pthread_rwlock_t *)&_func___16758, (const char *)0x22B4, v15, v16);
  selective_yield();
  return work;
}
