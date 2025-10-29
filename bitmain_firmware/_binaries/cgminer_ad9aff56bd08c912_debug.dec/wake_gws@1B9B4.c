int wake_gws()
{
  const char *v0; // r2
  int v1; // r3
  const char *v2; // r2
  int v3; // r3

  if ( pthread_mutex_lock(stgd_lock) )
    mutex_lock((pthread_mutex_t *)(&_func___16532.__align + 4), (const char *)0x1454, v0, v1);
  pthread_cond_signal(&gws_cond);
  if ( pthread_mutex_unlock(stgd_lock) )
    mutex_unlock_noyield((pthread_mutex_t *)(&_func___16532.__align + 4), (const char *)0x1456, v2, v3);
  return selective_yield();
}
