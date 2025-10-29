int sub_26A50()
{
  int v0; // r8
  char v2[4100]; // [sp+10h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v2, 0x1000u, 0, "<<<<<<<<<<<<<<<<<<<<exec %s start>>>>>>>>>>>>>>>>", "reload_config");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "reload_config",
    13,
    1061,
    20,
    v2);
  v0 = strcmp(s1, "127.0.0.1");
  if ( v0 )
    return -2147483643;
  V_LOCK();
  logfmt_raw(v2, 0x1000u, 0, "START %s", "load_default_config_without_restart");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "load_default_config_without_restart",
    35,
    1041,
    20,
    v2);
  if ( default_config
    && !access((const char *)default_config, 4)
    && (judge_load_config((char *)default_config) & 1) != 0 )
  {
    reload_pool();
  }
  V_LOCK();
  logfmt_raw(v2, 0x1000u, 0, "<<<<<<<<<<<<<<<<<<<<exec %s end>>>>>>>>>>>>>>>>>>", "reload_config");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/api_new.c",
    141,
    "reload_config",
    13,
    1068,
    20,
    v2);
  return v0;
}
