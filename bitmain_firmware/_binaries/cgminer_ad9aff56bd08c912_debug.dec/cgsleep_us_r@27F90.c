void __fastcall cgsleep_us_r(cgtimer_t *ts_start, int a2, int64_t us)
{
  __syscall_slong_t v4; // r3
  __time_t v5; // r2
  __time_t v6; // r4
  __syscall_slong_t v7; // r1
  timespec ts_end; // [sp+0h] [bp-Ch] BYREF

  us_to_timespec(&ts_end, a2, us);
  v4 = ts_end.tv_nsec + ts_start->tv_nsec;
  v5 = ts_end.tv_sec + ts_start->tv_sec;
  ts_end.tv_sec = v5;
  ts_end.tv_nsec = v4;
  if ( v4 <= 999999999 )
  {
    if ( v4 < 0 )
    {
      do
      {
        v4 += 1000000000;
        --v5;
      }
      while ( v4 < 0 );
      ts_end.tv_sec = v5;
      ts_end.tv_nsec = v4;
    }
  }
  else
  {
    v6 = v5 + 1;
    v7 = v4 - 1000000000;
    if ( v4 - 1000000000 > 999999999 )
    {
      v6 = v5 + 2;
      v7 = v4 - 2000000000;
    }
    ts_end.tv_sec = v6;
    ts_end.tv_nsec = v7;
  }
  while ( clock_nanosleep(1, 1, &ts_end, 0) == 4 )
    ;
}
