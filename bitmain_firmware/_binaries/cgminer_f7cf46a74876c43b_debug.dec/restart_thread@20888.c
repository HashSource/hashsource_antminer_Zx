int restart_thread()
{
  pool *v0; // r4
  pthread_t v1; // r0
  const char *v2; // r2
  int v3; // r3
  int v4; // r6
  const char *v5; // r2
  int v6; // r3
  int v7; // r4
  thr_info *v8; // r3
  pthread_rwlock_t *cgpu; // r5
  const char *v10; // r2
  int v11; // r3
  const char *v12; // r2
  int v13; // r3

  v0 = current_pool();
  v1 = pthread_self();
  pthread_detach(v1);
  pool_tset((int)v0, &v0->lagging);
  discard_stale();
  if ( pthread_rwlock_rdlock(&mining_thr_lock) )
    rd_lock((pthread_rwlock_t *)&_func___15760, (const char *)0x1496, v2, v3);
  v4 = mining_threads;
  v7 = pthread_rwlock_unlock(&mining_thr_lock);
  if ( v7 )
    rw_unlock((pthread_rwlock_t *)&_func___15760, (const char *)0x1498, v5, v6);
  selective_yield();
  if ( v4 > 0 )
  {
    do
    {
      v8 = mining_thr[v7];
      cgpu = (pthread_rwlock_t *)v8->cgpu;
      if ( cgpu && !cgpu[1].__readers )
      {
        v8->work_restart = 1;
        flush_queue(cgpu);
        (*(void (__fastcall **)(pthread_rwlock_t *))(cgpu->__writers + 76))(cgpu);
      }
      ++v7;
    }
    while ( v4 != v7 );
  }
  if ( pthread_mutex_lock(&restart_lock) )
    mutex_lock((pthread_mutex_t *)&_func___15760, (const char *)0x14A4, v10, v11);
  pthread_cond_broadcast(&restart_cond);
  if ( pthread_mutex_unlock(&restart_lock) )
    mutex_unlock_noyield((pthread_mutex_t *)&_func___15760, (const char *)0x14A6, v12, v13);
  selective_yield();
  return 0;
}
