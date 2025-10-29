// Alternative name is 'submit_tested_work.part.54'
int __fastcall submit_tested_work_0(thr_info *thr, work *work)
{
  const char *v2; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  LOWORD(v2) = -2796;
  HIWORD(v2) = (unsigned int)"rity" >> 16;
  snprintf(tmp42, 0x1000u, v2, "submit_tested_work", thr->cgpu->drv->name, thr->cgpu->device_id);
  applog(7, tmp42, 0);
  return 0;
}
