void __fastcall tq_freeze(thread_q *tq)
{
  tq_freezethaw(tq, 1);
}
