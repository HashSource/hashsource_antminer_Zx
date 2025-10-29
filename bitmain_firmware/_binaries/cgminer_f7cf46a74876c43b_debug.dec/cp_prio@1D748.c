int cp_prio()
{
  const char *v0; // r2
  int v1; // r3
  const char *v2; // r2
  int v3; // r3
  const char *v4; // r2
  int v5; // r3
  int prio; // r4
  const char *v7; // r2
  int v8; // r3

  if ( pthread_mutex_lock(&control_lock.mutex) )
    mutex_lock((pthread_mutex_t *)&_func___16209, (const char *)0x1B7C, v0, v1);
  if ( pthread_rwlock_rdlock(&control_lock.rwlock) )
    rd_lock((pthread_rwlock_t *)&_func___16209, (const char *)0x1B7C, v2, v3);
  if ( pthread_mutex_unlock(&control_lock.mutex) )
    mutex_unlock_noyield((pthread_mutex_t *)&_func___16209, (const char *)0x1B7C, v4, v5);
  prio = currentpool->prio;
  if ( pthread_rwlock_unlock(&control_lock.rwlock) )
    rw_unlock((pthread_rwlock_t *)&_func___16209, (const char *)0x1B7E, v7, v8);
  selective_yield();
  return prio;
}
