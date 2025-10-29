int __fastcall fan_control_info_init(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        float a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  char var1004[4104]; // [sp+38h] [bp-1004h] BYREF
  int varg_r0; // [sp+1048h] [bp+Ch]
  int varg_r1; // [sp+104Ch] [bp+10h]
  int varg_r2; // [sp+1050h] [bp+14h]
  int varg_r3; // [sp+1054h] [bp+18h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  dword_1716CC = a1;
  dword_1716D0 = a2;
  dword_1716D4 = a3;
  dword_1716D8 = a4;
  dword_1716DC = a5;
  dword_1716E0 = a6;
  flt_1716E4 = a7;
  dword_1716E8 = a8;
  dword_1716EC = a9;
  dword_1716F0 = a10;
  dword_1716F4 = a11;
  dword_1716F8 = a12;
  dword_1716FC = a13;
  memset(&flt_174250, 0, 0x2Cu);
  if ( dword_1716CC == 2 )
  {
    LODWORD(flt_174260) = dword_1716F0;
    flt_174258 = (float)SLODWORD(flt_1716E4);
    LODWORD(flt_174264) = dword_1716F4;
    LODWORD(flt_174268) = dword_1716F8;
    flt_174254 = (float)dword_1716D0;
    LODWORD(flt_17426C) = dword_1716FC;
    flt_174250 = (float)dword_1716D4;
  }
  V_LOCK();
  logfmt_raw(
    var1004,
    0x1000u,
    0,
    "startup P: %f, p: %f, i: %f, d: %f   target: %f, min %f, max %f",
    flt_174260,
    flt_174264,
    flt_174268,
    flt_17426C,
    flt_174258,
    flt_174254,
    flt_174250);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/set_pwm_by_temp.c",
    160,
    "fan_control_info_init",
    21,
    344,
    40,
    var1004);
  return 0;
}
