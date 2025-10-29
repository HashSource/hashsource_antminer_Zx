int start_api_thread()
{
  int v0; // r5
  char v2[4100]; // [sp+10h] [bp-1004h] BYREF

  dword_1868C8 = 3;
  pthread_attr_init((pthread_attr_t *)&dword_1868CC[1]);
  v0 = pthread_create(
         dword_1868CC,
         (const pthread_attr_t *)&dword_1868CC[1],
         (void *(*)(void *))sub_548D4,
         &dword_1868C8);
  pthread_attr_destroy((pthread_attr_t *)&dword_1868CC[1]);
  if ( !v0 )
    return 0;
  V_LOCK();
  logfmt_raw(v2, 0x1000u, 0, "api thread create failed");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/check_pool.c",
    155,
    "start_api_thread",
    16,
    139,
    100,
    v2);
  return 5;
}
