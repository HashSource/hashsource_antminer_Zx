int __fastcall ms_tdiff(timeval *end, timeval *start)
{
  int v2; // r2

  v2 = end->tv_sec - start->tv_sec;
  if ( v2 > 3600 )
    return 3600000;
  else
    return (end->tv_usec - start->tv_usec) / 1000 + 1000 * v2;
}
