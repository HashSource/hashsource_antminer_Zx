int __fastcall set_initial_interval_time(int a1, int a2)
{
  char v5[4100]; // [sp+10h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v5, 0x1000u, 0, "%s...", "set_initial_interval_time");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_eth_2280/backend_eth_2280.c",
    175,
    "set_initial_interval_time",
    25,
    168,
    20,
    v5);
  sub_6F7D4(a1, 59, a2);
  usleep(0x2710u);
  return 0;
}
