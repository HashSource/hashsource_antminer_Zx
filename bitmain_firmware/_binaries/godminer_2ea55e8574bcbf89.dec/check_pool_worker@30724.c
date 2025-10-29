int check_pool_worker()
{
  int v0; // r4
  int v1; // r6
  int v2; // r3
  _BYTE *v3; // r3
  int v4; // r10
  char v6[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( total_pools <= 0 )
    goto LABEL_10;
  v0 = 0;
  v1 = 0;
  do
  {
    while ( 1 )
    {
      v2 = *(_DWORD *)(pools + 4 * v0);
      if ( **(_BYTE **)(v2 + 12) )
        break;
LABEL_3:
      if ( total_pools <= ++v0 )
        goto LABEL_8;
    }
    v3 = *(_BYTE **)(v2 + 16);
    v4 = (unsigned __int8)*v3;
    if ( *v3 )
    {
      ++v1;
      goto LABEL_3;
    }
    ++v0;
    V_LOCK();
    logfmt_raw(v6, 0x1000u, v4, "Blank worker exists.");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/pool.c",
      138,
      "check_pool_worker",
      17,
      419,
      100,
      v6);
  }
  while ( total_pools > v0 );
LABEL_8:
  if ( v1 )
    return 0;
LABEL_10:
  V_LOCK();
  logfmt_raw(v6, 0x1000u, 0, "No valid pools, please configure them first!");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/pool.c",
    138,
    "check_pool_worker",
    17,
    425,
    100,
    v6);
  return -1;
}
