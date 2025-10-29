bool __fastcall tq_push(thread_q *tq, void *data)
{
  _DWORD *v4; // r0
  _DWORD *v5; // r4
  list_head *v6; // r6
  const char *v7; // r2
  int v8; // r3
  list_head *prev; // r3
  char v10; // r7
  int v11; // r3

  v4 = calloc(1u, 0xCu);
  v5 = v4;
  if ( v4 )
  {
    *v4 = data;
    v6 = (list_head *)(v4 + 1);
    v4[1] = v4 + 1;
    v4[2] = v4 + 1;
    if ( pthread_mutex_lock(&tq->mutex) )
      mutex_lock_0((pthread_mutex_t *)&_func___11752, (const char *)0x4F0, v7, v8);
    if ( tq->frozen )
    {
      v10 = 0;
      free(v5);
    }
    else
    {
      prev = tq->q.prev;
      v10 = 1;
      v5[1] = tq;
      tq->q.prev = v6;
      v5[2] = prev;
      prev->next = v6;
    }
    pthread_cond_signal(&tq->cond);
    mutex_unlock_noyield_0(&tq->mutex, (const char *)&_func___11752, (const char *)0x4FB, v11);
    selective_yield();
    LOBYTE(v4) = v10;
  }
  return (char)v4;
}
