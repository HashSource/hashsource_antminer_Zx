void __fastcall thread_reportout(thr_info *thr)
{
  cgpu_info *cgpu; // r4

  thr->getwork = 1;
  cgtime(&thr->last);
  thr->cgpu->status = alive::LIFE_WELL;
  cgpu = thr->cgpu;
  cgpu->device_last_well = time(0);
}
