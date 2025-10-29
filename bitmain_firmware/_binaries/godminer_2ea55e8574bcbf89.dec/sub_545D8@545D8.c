int sub_545D8()
{
  char v1[4096]; // [sp+10h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v1, 0x1000u, 0, "Unable to set thread to low priority");
  V_UNLOCK();
  return zlog(
           g_zc,
           "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmin"
           "er-origin_godminer-new/miner_util/check_pool.c",
           155,
           "set_lowprio",
           11,
           18,
           20,
           v1);
}
