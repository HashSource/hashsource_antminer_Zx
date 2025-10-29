void __fastcall work_completed(cgpu_info *a1, work *a2)
{
  pthread_rwlock_t *p_qlock; // r5
  const char *v5; // r2
  int v6; // r3
  const char *v7; // r2
  int v8; // r3

  p_qlock = &a1->qlock;
  if ( pthread_rwlock_wrlock(&a1->qlock) )
    wr_lock((pthread_rwlock_t *)(&_func___16717.__align + 3), (const char *)0x2309, v5, v6);
  _work_completed(a1, a2);
  if ( pthread_rwlock_unlock(p_qlock) )
    rw_unlock((pthread_rwlock_t *)(&_func___16717.__align + 3), (const char *)0x230B, v7, v8);
  selective_yield();
  clean_work(a2);
  sub_12000(a2);
}
