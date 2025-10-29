void __fastcall timeval_to_spec(timespec *spec, const timeval *val)
{
  spec->tv_sec = val->tv_sec;
  spec->tv_nsec = 1000 * val->tv_usec;
}
