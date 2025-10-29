__int64 now()
{
  timeval tv; // [sp+0h] [bp+0h] BYREF

  gettimeofday(&tv, 0);
  return tv.tv_usec + 1000000LL * tv.tv_sec;
}
