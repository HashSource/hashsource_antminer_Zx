void __fastcall cgsleep_us(int64_t us)
{
  int v2; // r1
  cgtimer_t ts_start; // [sp+0h] [bp-Ch] BYREF

  clock_gettime(1, &ts_start);
  cgsleep_us_r(&ts_start, v2, us);
}
