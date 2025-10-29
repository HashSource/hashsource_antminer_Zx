int gpio_init()
{
  char v1[2048]; // [sp+10h] [bp-1800h] BYREF
  char v2[4096]; // [sp+810h] [bp-1000h] BYREF

  if ( dword_1852F4 )
  {
    strcpy(v1, "gpio re init");
    V_LOCK();
    logfmt_raw(v2, 0x1000u, 0, v1);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/platform/7007/7007_gpio.c",
      176,
      "gpio_init",
      9,
      98,
      80,
      v2);
  }
  else
  {
    pthread_mutex_init(&stru_1852F8, 0);
    dword_185310 = (int)new_c_map((int)sub_A9B70, 0, 0);
    pthread_mutex_init(&stru_185314, 0);
    dword_18532C = 1;
    pthread_create((pthread_t *)&dword_185330, 0, (void *(*)(void *))sub_AAD40, 0);
    dword_1852F4 = 1;
  }
  return 0;
}
