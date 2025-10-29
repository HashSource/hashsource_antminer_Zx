void __fastcall us_to_timespec(timespec *spec, int a2, int64_t us)
{
  timespec v4; // r2
  lldiv_t tvdiv; // [sp+8h] [bp-10h] BYREF

  lldiv(&tvdiv, a2, us, HIDWORD(us), 1000000, 0);
  v4.tv_sec = tvdiv.quot;
  v4.tv_nsec = 1000 * LODWORD(tvdiv.rem);
  *spec = v4;
}
