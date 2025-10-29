work *__fastcall _get_queued(cgpu_info *cgpu)
{
  work *unqueued_work; // r5
  work *v4; // r0

  unqueued_work = cgpu->unqueued_work;
  if ( unqueued_work )
  {
    if ( stale_work(cgpu->unqueued_work, 0) )
    {
      v4 = unqueued_work;
      unqueued_work = 0;
      discard_work(v4);
      wake_gws();
    }
    else
    {
      _add_queued(cgpu, unqueued_work);
    }
    cgpu->unqueued_work = 0;
  }
  return unqueued_work;
}
