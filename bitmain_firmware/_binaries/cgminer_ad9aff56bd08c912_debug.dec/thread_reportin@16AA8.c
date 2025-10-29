void __fastcall thread_reportin(thr_info *thr)
{
  cgpu_info *cgpu; // r4

  thr->getwork = 0;
  cgtime(&thr->last);
  thr->cgpu->status = alive::LIFE_WELL;
  cgpu = thr->cgpu;
  cgpu->device_last_well = time(0);
}
