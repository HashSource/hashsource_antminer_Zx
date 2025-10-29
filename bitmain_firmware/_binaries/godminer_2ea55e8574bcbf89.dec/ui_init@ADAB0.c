int ui_init()
{
  int v0; // r5
  char v2[2048]; // [sp+10h] [bp-1800h] BYREF
  char v3[4096]; // [sp+810h] [bp-1000h] BYREF

  if ( dword_185690 )
    return 0;
  if ( gpio_init() )
  {
    v0 = -1;
    strcpy(v2, "gpio init failed");
    V_LOCK();
    logfmt_raw(v3, 0x1000u, 0, v2);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/platform/7007/7007_ui.c",
      174,
      "ui_init",
      7,
      152,
      100,
      v3);
    return v0;
  }
  gpio_export(941);
  gpio_export(942);
  gpio_export(921);
  gpio_export(943);
  gpio_reg_callback(921, (int)sub_AD6A8);
  gpio_reg_callback(943, (int)sub_AD6A8);
  pthread_mutex_init(&stru_185660, 0);
  off_18567C = 0;
  dword_185680 = 0;
  dword_185684 = 0;
  dword_185688 = 0;
  dword_18568C = 0;
  dword_185678 = (int)new_c_map((int)sub_AD414, 0, 0);
  dword_18565C[0] = 1;
  pthread_create((pthread_t *)&dword_185694, 0, (void *(*)(void *))sub_AD424, 0);
  dword_185690 = 1;
  return 0;
}
