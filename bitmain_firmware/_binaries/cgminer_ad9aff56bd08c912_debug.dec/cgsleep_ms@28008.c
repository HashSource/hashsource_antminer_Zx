void __fastcall cgsleep_ms(int ms)
{
  cgtimer_t ts_start; // [sp+0h] [bp-8h] BYREF

  clock_gettime(1, &ts_start);
  cgsleep_ms_r(&ts_start, ms);
}
