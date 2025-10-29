bool __fastcall time_more(timeval *a, timeval *b)
{
  if ( a->tv_sec == b->tv_sec )
    return a->tv_usec > b->tv_usec;
  else
    return a->tv_sec > b->tv_sec;
}
