void *__fastcall tq_pop(thread_q *tq, const timespec *abstime)
{
  pthread_mutex_t *p_mutex; // r6
  const char *v5; // r2
  int v6; // r3
  list_head *next; // r4
  list_head *prev; // r2
  list_head *v9; // r1
  list_head *v10; // r5
  list_head *v11; // r3
  pthread_cond_t *p_cond; // r0
  int v14; // r0

  p_mutex = &tq->mutex;
  if ( pthread_mutex_lock(&tq->mutex) )
    mutex_lock_0((pthread_mutex_t *)(&_func___11752.__align + 2), (const char *)0x506, v5, v6);
  next = tq->q.next;
  if ( tq == (thread_q *)tq->q.next )
  {
    p_cond = &tq->cond;
    if ( abstime )
      v14 = pthread_cond_timedwait(p_cond, p_mutex, abstime);
    else
      v14 = pthread_cond_wait(p_cond, p_mutex);
    if ( v14 )
    {
      v10 = 0;
      goto out_0;
    }
    v11 = tq->q.next;
    if ( next == tq->q.next )
    {
      v10 = 0;
      goto out_0;
    }
    next = tq->q.next;
  }
  prev = next->prev;
  v9 = next->next;
  v10 = next[-1].prev;
  v9->prev = prev;
  prev->next = v9;
  next->next = 0;
  next->prev = 0;
  free(&next[-1].prev);
out_0:
  mutex_unlock_noyield_0(p_mutex, &_func___11752.__size[8], (const char *)0x519, (const int)v11);
  selective_yield();
  return v10;
}
