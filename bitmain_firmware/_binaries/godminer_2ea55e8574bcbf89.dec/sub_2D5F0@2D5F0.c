int sub_2D5F0()
{
  int result; // r0
  int v1; // r4
  char v2[4100]; // [sp+10h] [bp-1004h] BYREF

  result = remove("/nvdata/droaswitch");
  v1 = result;
  if ( result )
  {
    V_LOCK();
    logfmt_raw(v2, 0x1000u, 0, "dswitch file ret=%d", v1);
    V_UNLOCK();
    return zlog(
             g_zc,
             "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godm"
             "iner-origin_godminer-new/god-miner.c",
             143,
             "droa_macro_check",
             16,
             1553,
             60,
             v2);
  }
  return result;
}
