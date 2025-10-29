void __fastcall us_to_timeval(timeval *val, int a2, int64_t us)
{
  lldiv_t tvdiv; // [sp+8h] [bp-10h] BYREF

  lldiv(&tvdiv, a2, us, HIDWORD(us), 1000000, 0);
  *val = (timeval)__PAIR64__(tvdiv.rem, tvdiv.quot);
}
