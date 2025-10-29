int __fastcall pool_died(int *a1)
{
  pthread_mutex_t *v1; // r5
  int v3; // r6
  int result; // r0
  int *v5; // r7
  _DWORD v6[7]; // [sp+28h] [bp-1044h] BYREF
  int v7; // [sp+44h] [bp-1028h]
  _DWORD v8[7]; // [sp+48h] [bp-1024h] BYREF
  int v9; // [sp+64h] [bp-1008h]
  char v10[4100]; // [sp+68h] [bp-1004h] BYREF

  v1 = (pthread_mutex_t *)(a1 + 456);
  pthread_mutex_lock((pthread_mutex_t *)a1 + 76);
  v3 = *((unsigned __int8 *)a1 + 1904);
  *((_BYTE *)a1 + 1904) = 1;
  result = pthread_mutex_unlock(v1);
  if ( !v3 )
  {
    cgtime((struct timeval *)(a1 + 477));
    sub_2FC0C(a1, 1);
    pthread_mutex_lock(&mutex);
    v5 = (int *)dword_17322C;
    pthread_mutex_unlock(&mutex);
    V_LOCK();
    if ( a1 == v5 )
    {
      V_INT((int)v6, "poolno", *a1);
      logfmt_raw(v10, 0x1000u, 0, v7, v6[0], v6[1], v6[2], v6[3], v6[4], v6[5], v6[6], v7, "not responding!");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/pool.c",
        138,
        "pool_died",
        9,
        402,
        80,
        v10);
      return switch_pools();
    }
    else
    {
      V_INT((int)v8, "poolno", *a1);
      logfmt_raw(v10, 0x1000u, 0, v9, v8[0], v8[1], v8[2], v8[3], v8[4], v8[5], v8[6], v9, "failed to return work");
      V_UNLOCK();
      return zlog(
               g_zc,
               "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/go"
               "dminer-origin_godminer-new/pool.c",
               138,
               "pool_died",
               9,
               405,
               20,
               v10);
    }
  }
  return result;
}
