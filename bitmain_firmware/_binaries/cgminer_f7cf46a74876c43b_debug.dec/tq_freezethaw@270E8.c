void __fastcall tq_freezethaw(thread_q *tq, bool frozen)
{
  pthread_mutex_t *p_mutex; // r5
  const char *v5; // r2
  int v6; // r3
  int v7; // r3

  p_mutex = &tq->mutex;
  if ( pthread_mutex_lock(&tq->mutex) )
    mutex_lock_0((pthread_mutex_t *)&_func___11739, (const char *)0x4D4, v5, v6);
  tq->frozen = frozen;
  pthread_cond_signal(&tq->cond);
  mutex_unlock_noyield_0(p_mutex, (const char *)&_func___11739, (const char *)0x4D7, v7);
  selective_yield();
}
