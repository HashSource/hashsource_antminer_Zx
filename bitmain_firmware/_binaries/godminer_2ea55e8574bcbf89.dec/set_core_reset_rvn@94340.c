int __fastcall set_core_reset_rvn(int a1)
{
  char v3[4096]; // [sp+10h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "%s...", "set_core_reset_rvn");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_rvn_2020/backend_rvn_2020.c",
    175,
    "set_core_reset_rvn",
    18,
    206,
    40,
    v3);
  sub_9206C(a1, 2, 0);
  usleep(0x2710u);
  sub_9206C(a1, 2, 255);
  usleep(0x2710u);
  return 0;
}
