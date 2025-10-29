pool *current_pool()
{
  const char *v0; // r2
  int v1; // r3
  const char *v2; // r2
  int v3; // r3
  const char *v4; // r2
  int v5; // r3
  pool *v6; // r4
  const char *v7; // r2
  int v8; // r3

  if ( pthread_mutex_lock(&control_lock.mutex) )
    mutex_lock((pthread_mutex_t *)&_func___14527, (const char *)0x31C, v0, v1);
  if ( pthread_rwlock_rdlock(&control_lock.rwlock) )
    rd_lock((pthread_rwlock_t *)&_func___14527, (const char *)0x31C, v2, v3);
  if ( pthread_mutex_unlock(&control_lock.mutex) )
    mutex_unlock_noyield((pthread_mutex_t *)&_func___14527, (const char *)0x31C, v4, v5);
  v6 = currentpool;
  if ( pthread_rwlock_unlock(&control_lock.rwlock) )
    rw_unlock((pthread_rwlock_t *)&_func___14527, (const char *)0x31E, v7, v8);
  selective_yield();
  return v6;
}
