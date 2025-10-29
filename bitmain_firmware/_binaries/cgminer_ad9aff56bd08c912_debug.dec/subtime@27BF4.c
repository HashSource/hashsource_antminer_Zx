void __fastcall subtime(timeval *a, timeval *b)
{
  timeval v2; // kr00_8
  __time_t v3; // r2
  __suseconds_t v4; // r3
  timeval v5; // r2

  v2 = *b;
  v3 = a->tv_sec - b->tv_sec;
  b->tv_sec = v3;
  v4 = a->tv_usec - v2.tv_usec;
  b->tv_usec = v4;
  if ( v4 < 0 )
  {
    v5.tv_sec = v3 - 1;
    v5.tv_usec = v4 + 1000000;
    *b = v5;
  }
}
