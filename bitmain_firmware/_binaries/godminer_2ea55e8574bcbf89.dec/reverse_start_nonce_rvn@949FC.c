int __fastcall reverse_start_nonce_rvn(int a1, int a2)
{
  char v5[4100]; // [sp+10h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v5, 0x1000u, 0, "%s...", "reverse_start_nonce_rvn");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_rvn_2020/backend_rvn_2020.c",
    175,
    "reverse_start_nonce_rvn",
    23,
    259,
    20,
    v5);
  sub_9206C(a1, 31, a2);
  usleep(0x2710u);
  return 0;
}
