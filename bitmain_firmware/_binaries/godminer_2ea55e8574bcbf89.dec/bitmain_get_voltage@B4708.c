void bitmain_get_voltage()
{
  int v0; // [sp+10h] [bp-1810h] BYREF
  __int16 v1; // [sp+14h] [bp-180Ch]
  _DWORD v2[2]; // [sp+18h] [bp-1808h] BYREF
  char s[2048]; // [sp+20h] [bp-1800h] BYREF
  char v4[4096]; // [sp+820h] [bp-1000h] BYREF

  if ( dword_185764 || sub_B370C() >= 0 )
  {
    v2[1] = 0;
    v2[0] = 0;
    v0 = 50637397;
    v1 = 7;
    if ( sub_B2D80((void *)dword_185760, (unsigned __int8 *)&v0, 6u, (unsigned __int8 *)v2, 8u) )
    {
      strcpy(s, "get AD conversion N failed");
      V_LOCK();
      logfmt_raw(v4, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "_bitmain_get_AD_conversion_N",
        28,
        360,
        100,
        v4);
      strcpy(s, "can nont get voltage");
      V_LOCK();
      logfmt_raw(v4, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "bitmain_get_voltage",
        19,
        696,
        100,
        v4);
    }
    else
    {
      bitmain_convert_N_to_V();
    }
  }
  else
  {
    snprintf(s, 0x800u, "%s: auto exec bitmain_power_open, but open power failed", "bitmain_get_voltage");
    V_LOCK();
    logfmt_raw(v4, 0x1000u, 0, s);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
      177,
      "bitmain_get_voltage",
      19,
      692,
      100,
      v4);
  }
}
