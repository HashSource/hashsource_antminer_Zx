work *__fastcall make_clone(work *work)
{
  work *v2; // r4
  __time_t tv_sec; // r3

  v2 = make_work();
  copy_work(v2, work, 0);
  v2->clone = 1;
  cgtime(&v2->tv_cloned);
  tv_sec = v2->tv_staged.tv_sec;
  v2->longpoll = 0;
  v2->mandatory = 0;
  v2->tv_staged.tv_sec = tv_sec - 1;
  return v2;
}
