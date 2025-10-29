// Alternative name is 'decay_time.part.34'
void __fastcall decay_time_0(double f, double fadd, double fsecs, double interval)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double *v7; // r4

  v7 = (double *)LODWORD(f);
  exp(f);
  *v7 = (*v7 + v4 / v5 * (1.0 - 1.0 / (v5 / v6))) / (1.0 - 1.0 / (v5 / v6) + 1.0);
}
