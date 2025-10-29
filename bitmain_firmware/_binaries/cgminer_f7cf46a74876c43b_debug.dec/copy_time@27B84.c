void __fastcall copy_time(timeval *dest, const timeval *src)
{
  __suseconds_t tv_usec; // r3

  tv_usec = src->tv_usec;
  dest->tv_sec = src->tv_sec;
  dest->tv_usec = tv_usec;
}
