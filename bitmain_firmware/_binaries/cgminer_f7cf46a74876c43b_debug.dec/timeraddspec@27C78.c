void __fastcall timeraddspec(timespec *a, const timespec *b)
{
  __syscall_slong_t tv_nsec; // r3
  __int64 v3; // r2
  __time_t v4; // r5
  __syscall_slong_t v5; // r1

  tv_nsec = a->tv_nsec;
  LODWORD(v3) = a->tv_sec + b->tv_sec;
  a->tv_sec = v3;
  HIDWORD(v3) = tv_nsec + b->tv_nsec;
  a->tv_nsec = HIDWORD(v3);
  if ( SHIDWORD(v3) <= 999999999 )
  {
    if ( v3 < 0 )
    {
      do
      {
        HIDWORD(v3) += 1000000000;
        LODWORD(v3) = v3 - 1;
      }
      while ( v3 < 0 );
      *a = (timespec)v3;
    }
  }
  else
  {
    v4 = v3 + 1;
    v5 = HIDWORD(v3) - 1000000000;
    if ( HIDWORD(v3) - 1000000000 > 999999999 )
    {
      v4 = v3 + 2;
      v5 = HIDWORD(v3) - 2000000000;
    }
    a->tv_sec = v4;
    a->tv_nsec = v5;
  }
}
