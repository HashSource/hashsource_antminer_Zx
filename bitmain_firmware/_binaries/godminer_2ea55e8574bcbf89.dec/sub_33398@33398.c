int __fastcall sub_33398(int a1)
{
  char v3[4100]; // [sp+10h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "The provided character %c is invalid and was not rejected in preliminary hex checks!", a1);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/util.h",
    138,
    "get_value_from_lower_hex",
    24,
    41,
    100,
    v3);
  return -1;
}
