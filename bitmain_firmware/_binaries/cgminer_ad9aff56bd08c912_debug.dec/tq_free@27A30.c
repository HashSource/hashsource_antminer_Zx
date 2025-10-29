void __fastcall tq_free(thread_q *tq)
{
  list_head *next; // r2
  bool v3; // zf
  list_head **p_prev; // r0
  list_head **i; // r5
  list_head *v6; // r3

  if ( tq )
  {
    next = tq->q.next->next;
    v3 = tq == (thread_q *)tq->q.next;
    p_prev = &tq->q.next[-1].prev;
    for ( i = &next[-1].prev; !v3; i = &next[-1].prev )
    {
      v6 = p_prev[2];
      next->prev = v6;
      v6->next = next;
      free(p_prev);
      p_prev = i;
      next = i[1];
      v3 = i + 1 == (list_head **)tq;
    }
    pthread_cond_destroy(&tq->cond);
    pthread_mutex_destroy(&tq->mutex);
    sub_12000(tq);
  }
}
