int bitmain_power_version()
{
  int v0; // r5
  int v2; // [sp+10h] [bp-1810h] BYREF
  __int16 v3; // [sp+14h] [bp-180Ch]
  int v4; // [sp+18h] [bp-1808h] BYREF
  int v5; // [sp+1Ch] [bp-1804h]
  char s[2048]; // [sp+20h] [bp-1800h] BYREF
  char v7[4096]; // [sp+820h] [bp-1000h] BYREF

  if ( dword_185764 || (v0 = bitmain_power_open(), v0 >= 0) )
  {
    v5 = 0;
    v4 = 0;
    v2 = 33860181;
    v3 = 6;
    if ( sub_B2D80((void *)dword_185760, (unsigned __int8 *)&v2, 6u, (unsigned __int8 *)&v4, 8u) )
    {
      v0 = -2147482880;
      strcpy(s, "get power version failed");
      V_LOCK();
      logfmt_raw(v7, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "_bitmain_get_power_version",
        26,
        300,
        100,
        v7);
    }
    else
    {
      v0 = (unsigned __int16)v5;
      if ( (_WORD)v5 )
        dword_185768 = (unsigned __int16)v5;
    }
  }
  else
  {
    snprintf(s, 0x800u, "%s: auto exec bitmain_power_open, but open power failed", "bitmain_power_version");
    V_LOCK();
    logfmt_raw(v7, 0x1000u, 0, s);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
      177,
      "bitmain_power_version",
      21,
      681,
      100,
      v7);
  }
  return v0;
}
