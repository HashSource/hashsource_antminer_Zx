void __fastcall tq_thaw(thread_q *tq)
{
  tq_freezethaw(tq, 0);
}
