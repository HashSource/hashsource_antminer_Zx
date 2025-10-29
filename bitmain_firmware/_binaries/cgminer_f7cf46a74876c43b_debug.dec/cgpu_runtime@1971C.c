// local variable allocation has failed, the output may be wrong!
double __fastcall cgpu_runtime(cgpu_info *cgpu)
{
  cgpu_info *v1; // r4
  double result; // r0
  timeval now; // [sp+0h] [bp-8h] BYREF

  if ( cgpu->dev_start_tv.tv_sec )
  {
    v1 = cgpu;
    cgtime(&now);
    *(double *)&cgpu = tdiff(&now, &v1->dev_start_tv);
  }
  LODWORD(result) = cgpu;
  return result;
}
