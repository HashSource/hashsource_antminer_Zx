bool __fastcall check_value_valid_with_stdd(__int64 a1, int a2)
{
  double v2; // d0
  int *v4; // r3
  int v5; // r2
  int v6; // t1
  double v7; // d7
  double v8; // d10
  double v9; // d8
  char v11[4096]; // [sp+28h] [bp-1000h] BYREF

  if ( a1 <= 0 )
  {
    v7 = 0.0;
  }
  else
  {
    v4 = (int *)a1;
    v5 = 0;
    do
    {
      v6 = *v4++;
      v5 += v6;
    }
    while ( (int *)(a1 + 4 * HIDWORD(a1)) != v4 );
    v7 = (double)v5;
  }
  v8 = v7 / (double)SHIDWORD(a1);
  calc_stdd(a1);
  V_LOCK();
  v9 = (double)a2;
  logfmt_raw(
    v11,
    0x1000u,
    0,
    "mean:%.4f, stdd:%.4f, min_value:%.4f, max_value:%.4f, to_check:%.4f",
    v8,
    v2,
    v8 - v2,
    v2 + v8,
    v9);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/util.c",
    138,
    "check_value_valid_with_stdd",
    27,
    559,
    20,
    v11);
  return v9 >= v8 - v2 && v9 <= v2 + v8 || v2 < 2.0;
}
