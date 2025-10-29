int __fastcall cg_timeval_subtract(timeval *result, timeval *x, timeval *y)
{
  __time_t v3; // r4
  __suseconds_t v4; // r3

  if ( x->tv_sec > y->tv_sec || x->tv_sec == y->tv_sec && x->tv_usec > y->tv_usec )
    return -1;
  v3 = y->tv_sec - x->tv_sec;
  result->tv_sec = v3;
  v4 = y->tv_usec - x->tv_usec;
  result->tv_usec = v4;
  if ( v4 < 0 )
  {
    result->tv_sec = v3 - 1;
    result->tv_usec = v4 + 1000000;
  }
  return 0;
}
