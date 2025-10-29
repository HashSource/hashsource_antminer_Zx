int __fastcall i2c_uninit(int a1)
{
  int v1; // r4
  _DWORD *v2; // r5
  int result; // r0
  int v4; // [sp+14h] [bp-7FCh] BYREF
  char s[2048]; // [sp+18h] [bp-7F8h] BYREF
  char v6[4100]; // [sp+818h] [bp+8h] BYREF

  v4 = a1;
  v1 = pthread_mutex_lock(&stru_1860A0);
  if ( v1 )
  {
    strcpy(s, "failed to i2c lock");
    V_LOCK();
    logfmt_raw(v6, 0x1000u, 0, s);
    V_UNLOCK();
    return zlog(
             g_zc,
             "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godm"
             "iner-origin_godminer-new/backend/device/hal/platform/7007/7007_i2c.c",
             175,
             "i2c_uninit",
             10,
             61,
             100,
             v6);
  }
  else
  {
    if ( exists_c_map((int *)dword_18609C, (int)&v4) == (int *)1 )
    {
      snprintf(s, 0x800u, "remove %d from callback list", v4);
      V_LOCK();
      logfmt_raw(v6, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/platform/7007/7007_i2c.c",
        175,
        "i2c_uninit",
        10,
        65,
        20,
        v6);
      remove_c_map((int *)dword_18609C, (int)&v4);
    }
    else
    {
      snprintf(s, 0x800u, "ctx(%d) is not inited", v4);
      V_LOCK();
      logfmt_raw(v6, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/platform/7007/7007_i2c.c",
        175,
        "i2c_uninit",
        10,
        68,
        80,
        v6);
    }
    v2 = new_iterator_c_map(dword_18609C);
    if ( ((int (*)(void))*v2)() )
    {
      do
        ++v1;
      while ( ((int (__fastcall *)(_DWORD *))*v2)(v2) );
      delete_iterator_c_map(v2);
      pthread_mutex_unlock(&stru_1860A0);
      snprintf(s, 0x800u, "still have %d nodes", v1);
      V_LOCK();
      logfmt_raw(v6, 0x1000u, 0, s);
      V_UNLOCK();
      return zlog(
               g_zc,
               "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/go"
               "dminer-origin_godminer-new/backend/device/hal/platform/7007/7007_i2c.c",
               175,
               "i2c_uninit",
               10,
               84,
               20,
               v6);
    }
    else
    {
      delete_iterator_c_map(v2);
      pthread_mutex_unlock(&stru_1860A0);
      strcpy(s, "all i2c uninited");
      V_LOCK();
      logfmt_raw(v6, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/platform/7007/7007_i2c.c",
        175,
        "i2c_uninit",
        10,
        79,
        20,
        v6);
      dword_186098 = 0;
      result = delete_c_map((void (__fastcall ***)(_DWORD))dword_18609C);
      dword_18609C = 0;
    }
  }
  return result;
}
