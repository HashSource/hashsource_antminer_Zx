work *__fastcall get_queued(cgpu_info *a1)
{
  pthread_rwlock_t *p_qlock; // r4
  const char *v3; // r2
  int v4; // r3
  work *queued; // r5
  const char *v6; // r2
  int v7; // r3

  p_qlock = &a1->qlock;
  if ( pthread_rwlock_wrlock(&a1->qlock) )
    wr_lock((pthread_rwlock_t *)(&_func___15639.__align + 3), (const char *)0x2270, v3, v4);
  queued = _get_queued(a1);
  if ( pthread_rwlock_unlock(p_qlock) )
    rw_unlock((pthread_rwlock_t *)(&_func___15639.__align + 3), (const char *)0x2272, v6, v7);
  selective_yield();
  return queued;
}
