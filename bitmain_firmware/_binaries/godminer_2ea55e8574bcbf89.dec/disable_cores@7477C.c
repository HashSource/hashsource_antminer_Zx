int __fastcall disable_cores(int a1)
{
  char v3[4096]; // [sp+10h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "%s...", "disable_cores");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_eth_2280/backend_eth_2280.c",
    175,
    "disable_cores",
    13,
    808,
    20,
    v3);
  sub_6F7D4(a1, 13, 0);
  usleep((__useconds_t)&stru_1869C.st_value);
  return 0;
}
