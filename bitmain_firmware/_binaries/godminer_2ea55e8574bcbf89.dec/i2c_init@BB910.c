int i2c_init()
{
  int v0; // r4
  int *v1; // r6
  int v3; // [sp+14h] [bp-1804h] BYREF
  char v4[2040]; // [sp+18h] [bp-1800h] BYREF
  _DWORD v5[1024]; // [sp+818h] [bp-1000h] BYREF

  v3 = -1;
  if ( platform_inited )
  {
    v0 = dword_186098;
    if ( dword_186098 )
    {
      v1 = (int *)dword_18609C;
    }
    else
    {
      v1 = new_c_map((int)sub_BB7B4, 0, 0);
      dword_18609C = (int)v1;
      pthread_mutex_init(&stru_1860A0, 0);
      v0 = dword_186098;
    }
    dword_186098 = v0 + 1;
    v3 = v0 + 1;
    v5[0] = 0;
    v5[1] = 0;
    insert_c_map(v1, &v3, 4u, v5, 8u);
    return v3;
  }
  else
  {
    strcpy(v4, "please init platform first!!");
    V_LOCK();
    logfmt_raw((char *)v5, 0x1000u, 0, v4);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/platform/7007/7007_i2c.c",
      175,
      "i2c_init",
      8,
      40,
      100,
      v5);
    return -2;
  }
}
