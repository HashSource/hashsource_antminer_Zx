void __fastcall cgtimer_time(cgtimer_t *ts_start)
{
  j_clock_gettime(1, ts_start);
}
