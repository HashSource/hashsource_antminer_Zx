work *__fastcall get_queue_work(thr_info *thr, cgpu_info *cgpu, int thr_id)
{
  work *work; // r4

  work = get_work(thr, thr_id);
  add_queued(cgpu, work);
  return work;
}
