void __fastcall cgsleep_ms_r(cgtimer_t *ts_start, int ms)
{
  __syscall_slong_t v3; // r3
  __time_t v4; // r2
  __time_t v5; // r4
  __syscall_slong_t v6; // r1
  timespec ts_end; // [sp+0h] [bp-Ch] BYREF

  ms_to_timespec(&ts_end, ms, ms);
  v3 = ts_end.tv_nsec + ts_start->tv_nsec;
  v4 = ts_end.tv_sec + ts_start->tv_sec;
  ts_end.tv_sec = v4;
  ts_end.tv_nsec = v3;
  if ( v3 <= 999999999 )
  {
    if ( v3 < 0 )
    {
      do
      {
        v3 += 1000000000;
        --v4;
      }
      while ( v3 < 0 );
      ts_end.tv_sec = v4;
      ts_end.tv_nsec = v3;
    }
  }
  else
  {
    v5 = v4 + 1;
    v6 = v3 - 1000000000;
    if ( v3 - 1000000000 > 999999999 )
    {
      v5 = v4 + 2;
      v6 = v3 - 2000000000;
    }
    ts_end.tv_sec = v5;
    ts_end.tv_nsec = v6;
  }
  while ( clock_nanosleep(1, 1, &ts_end, 0) == 4 )
    ;
}
