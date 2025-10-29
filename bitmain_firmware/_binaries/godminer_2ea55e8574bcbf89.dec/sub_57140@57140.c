int __fastcall sub_57140(int a1)
{
  char v3[4100]; // [sp+10h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "%s unknow temp type %d", a1);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/set_pwm_by_temp.c",
    160,
    "get_temp",
    8,
    169,
    100,
    v3);
  return 0x7FFFFFFF;
}
