int __fastcall pic1704_get_an_voltage2(char a1, int a2)
{
  float v2; // s0
  float v3; // s1
  int result; // r0
  double v6; // d9
  unsigned int v7; // [sp+2Ch] [bp-180Ch] BYREF
  unsigned int v8; // [sp+30h] [bp-1808h] BYREF
  unsigned int v9; // [sp+34h] [bp-1804h] BYREF
  char s[2040]; // [sp+38h] [bp-1800h] BYREF
  char v11[4096]; // [sp+838h] [bp-1000h] BYREF

  v7 = 0;
  v8 = 0;
  v9 = 0;
  result = pic1704_get_all_voltage(a1, &v7, &v8, &v9);
  if ( (_BYTE)result )
  {
    strcpy(s, "Received an voltage response.");
    V_LOCK();
    logfmt_raw(v11, 0x1000u, 0, s);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/drv_pic/pic_1704.c",
      169,
      "pic1704_get_an_voltage2",
      23,
      444,
      20,
      v11);
    snprintf(
      s,
      0x800u,
      "an0 = %f, an2 %f, an6 %f.",
      (double)v7 * 3.3 * 0.0009765625,
      (double)v8 * 3.3 * 0.0009765625,
      (double)v9 * 3.3 * 0.0009765625);
    V_LOCK();
    logfmt_raw(v11, 0x1000u, 0, s);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/drv_pic/pic_1704.c",
      169,
      "pic1704_get_an_voltage2",
      23,
      445,
      20,
      v11);
    if ( a2 && ((v6 = (double)v9 * 3.3 * 0.0009765625, v2 > v6) || v3 < v6) )
    {
      strcpy(s, "Ref an vol too high or too low.");
      V_LOCK();
      logfmt_raw(v11, 0x1000u, 0, s);
      V_UNLOCK();
      return zlog(
               g_zc,
               "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/go"
               "dminer-origin_godminer-new/backend/device/hal/drv_pic/pic_1704.c",
               169,
               "pic1704_get_an_voltage2",
               23,
               451,
               20,
               v11);
    }
    else
    {
      return sub_A5C30(v8);
    }
  }
  return result;
}
