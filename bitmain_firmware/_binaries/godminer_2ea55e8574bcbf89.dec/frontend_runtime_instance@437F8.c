int frontend_runtime_instance()
{
  int v0; // r4
  char v2[4100]; // [sp+10h] [bp-1004h] BYREF

  v0 = dword_173E38;
  if ( !dword_173E38 )
  {
    V_LOCK();
    logfmt_raw(v2, 0x1000u, 0, "frontend runtime type not set");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/frontend/frontend_interface.c",
      161,
      "frontend_runtime_instance",
      25,
      74,
      100,
      v2);
  }
  return v0;
}
