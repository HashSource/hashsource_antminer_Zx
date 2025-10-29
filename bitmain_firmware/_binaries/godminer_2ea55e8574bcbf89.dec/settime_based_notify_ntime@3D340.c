int __fastcall settime_based_notify_ntime(const char *a1)
{
  int v1; // r0
  int v2; // r4
  unsigned int v4; // r6
  struct timeval tv; // [sp+10h] [bp-1008h] BYREF
  char v6[4096]; // [sp+18h] [bp-1000h] BYREF

  v1 = strtol(a1, 0, 16);
  if ( v1 )
    v2 = ((unsigned __int8)byte_173CA5 ^ 1) & 1;
  else
    v2 = 0;
  if ( v2 )
  {
    v4 = v1;
    tv.tv_usec = 0;
    tv.tv_sec = 0;
    gettimeofday(&tv, 0);
    if ( tv.tv_sec < v4 )
    {
      tv.tv_sec = v4;
      settimeofday(&tv, 0);
      V_LOCK();
      logfmt_raw(v6, 0x1000u, 0, "settime notify.ntime successfuly");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/frontend/frontend_base.c",
        156,
        "settime_based_notify_ntime",
        26,
        383,
        60,
        v6);
      byte_173CA5 = 1;
    }
    else
    {
      return 0;
    }
  }
  return v2;
}
