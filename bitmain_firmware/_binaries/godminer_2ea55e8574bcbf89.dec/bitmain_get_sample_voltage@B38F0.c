int bitmain_get_sample_voltage()
{
  int result; // r0
  int v1; // [sp+10h] [bp-1814h] BYREF
  __int16 v2; // [sp+14h] [bp-1810h]
  _DWORD v3[2]; // [sp+18h] [bp-180Ch] BYREF
  char s[2048]; // [sp+20h] [bp-1804h] BYREF
  char v5[4100]; // [sp+820h] [bp-1004h] BYREF

  if ( dword_185764 || sub_B370C() >= 0 )
  {
    v3[1] = 0;
    v3[0] = 0;
    v1 = 67414613;
    v2 = 8;
    result = sub_B2D80((void *)dword_185760, (unsigned __int8 *)&v1, 6u, (unsigned __int8 *)v3, 8u);
    if ( result )
    {
      strcpy(s, "get sample N failed");
      V_LOCK();
      logfmt_raw(v5, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "_bitmain_get_sample_N",
        21,
        459,
        100,
        v5);
      strcpy(s, "can nont get sample voltage");
      V_LOCK();
      logfmt_raw(v5, 0x1000u, 0, s);
      V_UNLOCK();
      return zlog(
               g_zc,
               "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/go"
               "dminer-origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
               177,
               "bitmain_get_sample_voltage",
               26,
               571,
               100,
               v5);
    }
  }
  else
  {
    snprintf(s, 0x800u, "%s: auto exec bitmain_power_open, but open power failed", "bitmain_get_sample_voltage");
    V_LOCK();
    logfmt_raw(v5, 0x1000u, 0, s);
    V_UNLOCK();
    return zlog(
             g_zc,
             "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godm"
             "iner-origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
             177,
             "bitmain_get_sample_voltage",
             26,
             567,
             100,
             v5);
  }
  return result;
}
