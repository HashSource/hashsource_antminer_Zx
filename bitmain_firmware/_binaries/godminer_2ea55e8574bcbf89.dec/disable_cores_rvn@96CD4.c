int __fastcall disable_cores_rvn(int a1)
{
  char v3[4096]; // [sp+10h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "%s...", "disable_cores_rvn");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_rvn_2020/backend_rvn_2020.c",
    175,
    "disable_cores_rvn",
    17,
    787,
    20,
    v3);
  sub_9206C(a1, 160, 0);
  usleep((__useconds_t)&stru_1869C.st_value);
  return 0;
}
