work *__fastcall copy_work_noffset(work *base_work, int noffset)
{
  work *work; // r4

  work = make_work();
  copy_work(work, base_work, noffset);
  return work;
}
