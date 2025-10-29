int __fastcall add_queued(cgpu_info *a1, work *a2)
{
  pthread_rwlock_t *p_qlock; // r4
  const char *v5; // r2
  int v6; // r3
  const char *v7; // r2
  int v8; // r3

  p_qlock = &a1->qlock;
  if ( pthread_rwlock_wrlock(&a1->qlock) )
    wr_lock((pthread_rwlock_t *)&_func___16717, (const char *)0x2279, v5, v6);
  _add_queued(a1, a2);
  if ( pthread_rwlock_unlock(p_qlock) )
    rw_unlock((pthread_rwlock_t *)&_func___16717, (const char *)0x227B, v7, v8);
  return selective_yield();
}
