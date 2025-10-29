int __fastcall setup_mac(int a1)
{
  char v3[4096]; // [sp+10h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "%s...", "setup_mac");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_eth_2280/backend_eth_2280.c",
    175,
    "setup_mac",
    9,
    524,
    20,
    v3);
  sub_6F7D4(a1, 143, 33489407);
  usleep(0x2710u);
  return 0;
}
