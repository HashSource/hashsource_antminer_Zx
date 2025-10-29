unsigned int __fastcall close_pic(unsigned int result)
{
  unsigned int v1; // r5
  unsigned int v2; // r6
  char s[2048]; // [sp+10h] [bp-1800h] BYREF
  char v4[4096]; // [sp+810h] [bp-1000h] BYREF

  v1 = result;
  if ( result > 0xF )
  {
    snprintf(s, 0x800u, "%s: Bad pic param, input chain is %d", "close_pic", result);
    V_LOCK();
    logfmt_raw(v4, 0x1000u, 0, s);
    V_UNLOCK();
    return zlog(
             g_zc,
             "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godm"
             "iner-origin_godminer-new/backend/device/hal/drv_pic/pic_1704.c",
             169,
             "close_pic",
             9,
             764,
             100,
             v4);
  }
  else
  {
    v2 = 2 * result;
    if ( g_bitmain_pic_state[2 * result] || g_bitmain_pic_state[v2 + 1] )
    {
      pthread_mutex_lock(&i2c_mutex_all);
      iic_uninit(g_bitmain_pic_state[2 * v1]);
      g_bitmain_pic_state[v2 + 1] = 0;
      return pthread_mutex_unlock(&i2c_mutex_all);
    }
  }
  return result;
}
