double __fastcall us_tdiff(timeval *end, timeval *start)
{
  double result; // r0

  if ( end->tv_sec - start->tv_sec <= 60 )
  {
    end = (timeval *)1000000;
    start = (timeval *)start->tv_usec;
  }
  LODWORD(result) = end;
  HIDWORD(result) = start;
  return result;
}
