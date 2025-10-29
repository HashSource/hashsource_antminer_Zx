thr_info *__fastcall get_thread(int a1)
{
  const char *v2; // r2
  int v3; // r3
  thr_info *v4; // r4
  const char *v5; // r2
  int v6; // r3

  if ( pthread_rwlock_rdlock(&mining_thr_lock) )
    rd_lock((pthread_rwlock_t *)(&_func___14460.__align + 6), (const char *)0x266, v2, v3);
  v4 = mining_thr[a1];
  if ( pthread_rwlock_unlock(&mining_thr_lock) )
    rw_unlock((pthread_rwlock_t *)(&_func___14460.__align + 6), (const char *)0x268, v5, v6);
  selective_yield();
  return v4;
}
