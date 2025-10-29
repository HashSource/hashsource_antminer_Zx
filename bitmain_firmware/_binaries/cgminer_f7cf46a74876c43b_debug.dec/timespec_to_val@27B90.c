void __fastcall timespec_to_val(timeval *val, const timespec *spec)
{
  val->tv_sec = spec->tv_sec;
  val->tv_usec = spec->tv_nsec / 1000;
}
