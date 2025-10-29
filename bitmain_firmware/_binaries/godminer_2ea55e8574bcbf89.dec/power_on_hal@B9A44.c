int __fastcall power_on_hal(int a1, unsigned __int16 a2, int a3)
{
  int is_pic_mcu_en; // r6
  int v8; // r6
  int v9; // r6
  char v10[4096]; // [sp+10h] [bp-1000h] BYREF

  chain_reset_low(g_chain_info[2 * a1]);
  sleep(1u);
  is_pic_mcu_en = platform_is_pic_mcu_en();
  if ( is_pic_mcu_en )
  {
    v9 = pic1704_reset(g_chain_info[2 * a1]);
    usleep(0x493E0u);
    is_pic_mcu_en = v9 + pic1704_jump_to_app(g_chain_info[2 * a1]);
    usleep(0x493E0u);
  }
  if ( !a3 && platform_is_pic_mcu_en() )
    set_chain_isl_voltage(g_chain_info[2 * a1], a2);
  if ( !platform_is_pic_mcu_en()
    || (v8 = is_pic_mcu_en + pic1704_enable_disable_dc_dc(g_chain_info[2 * a1], 1), v8 == 3) )
  {
    if ( opt_algo != 11 )
      sleep(1u);
    chain_reset_high(g_chain_info[2 * a1]);
    usleep(0x493E0u);
    chain_reset_low(g_chain_info[2 * a1]);
    sleep(1u);
    chain_reset_high(g_chain_info[2 * a1]);
    usleep(0x493E0u);
    return 0;
  }
  else
  {
    V_LOCK();
    logfmt_raw(v10, 0x1000u, 0, "chain %d, pic init failed, err:%d!!!", g_chain_info[2 * a1], v8);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/platform_device_hal.c",
      168,
      "power_on_hal",
      12,
      490,
      100,
      v10);
    return -1;
  }
}
