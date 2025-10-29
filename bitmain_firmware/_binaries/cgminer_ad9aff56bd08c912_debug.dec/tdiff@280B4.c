double __fastcall tdiff(timeval *end, timeval *start)
{
  double result; // r0

  HIDWORD(result) = start->tv_sec;
  LODWORD(result) = end;
  return result;
}
