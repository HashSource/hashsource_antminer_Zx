void __fastcall ms_to_timeval(timeval *val, int a2, int64_t ms)
{
  timeval v4; // r2
  lldiv_t tvdiv; // [sp+8h] [bp-10h] BYREF

  lldiv(&tvdiv, a2, ms, HIDWORD(ms), 1000, 0);
  v4.tv_sec = tvdiv.quot;
  v4.tv_usec = 1000 * LODWORD(tvdiv.rem);
  *val = v4;
}
