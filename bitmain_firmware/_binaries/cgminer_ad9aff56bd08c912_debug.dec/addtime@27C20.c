void __fastcall addtime(timeval *a, timeval *b)
{
  __suseconds_t tv_usec; // r5
  __time_t v3; // r2
  __suseconds_t v4; // r3
  timeval v5; // r2

  tv_usec = b->tv_usec;
  v3 = a->tv_sec + b->tv_sec;
  b->tv_sec = v3;
  v4 = a->tv_usec + tv_usec;
  b->tv_usec = v4;
  if ( v4 > 999999 )
  {
    v5.tv_usec = v4 - 1000000;
    v5.tv_sec = v3 + 1;
    *b = v5;
  }
}
