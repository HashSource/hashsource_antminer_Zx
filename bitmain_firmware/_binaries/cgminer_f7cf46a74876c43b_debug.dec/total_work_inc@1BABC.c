uint32_t total_work_inc()
{
  const char *v0; // r2
  int v1; // r3
  const char *v2; // r2
  int v3; // r3
  uint32_t v4; // r4
  const char *v5; // r2
  int v6; // r3
  const char *v7; // r2
  int v8; // r3

  if ( pthread_mutex_lock(&control_lock.mutex) )
    mutex_lock((pthread_mutex_t *)(&_func___15752.__align + 4), (const char *)0x8E1, v0, v1);
  if ( pthread_rwlock_wrlock(&control_lock.rwlock) )
    wr_lock((pthread_rwlock_t *)(&_func___15752.__align + 4), (const char *)0x8E1, v2, v3);
  v4 = total_work++;
  if ( pthread_rwlock_unlock(&control_lock.rwlock) )
    rw_unlock((pthread_rwlock_t *)(&_func___15752.__align + 4), (const char *)0x8E3, v5, v6);
  if ( pthread_mutex_unlock(&control_lock.mutex) )
    mutex_unlock_noyield((pthread_mutex_t *)(&_func___15752.__align + 4), (const char *)0x8E3, v7, v8);
  selective_yield();
  return v4;
}
