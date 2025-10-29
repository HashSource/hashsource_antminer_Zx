time_t set_miner_start_time()
{
  time_t result; // r0
  int v1; // r4
  char *v2; // r0
  struct sysinfo info; // [sp+10h] [bp-1140h] BYREF
  char s[256]; // [sp+50h] [bp-1100h] BYREF
  char v5[4096]; // [sp+150h] [bp-1000h] BYREF

  if ( sysinfo(&info) )
  {
    v1 = *_errno_location();
    v2 = strerror(v1);
    sprintf(s, "Failed to get sysinfo, errno:%u, reason:%s", v1, v2);
    result = time(0);
    dword_173070 = result + 1;
    dword_173074 = result;
  }
  else
  {
    dword_173074 = info.uptime;
    dword_173070 = info.uptime + 1;
    sprintf(s, "%s total_tv_start_sys=%ld total_tv_end_sys=%ld", "set_miner_start_time", info.uptime, info.uptime + 1);
    V_LOCK();
    logfmt_raw(v5, 0x1000u, 0, "%s", s);
    V_UNLOCK();
    return zlog(
             g_zc,
             "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godm"
             "iner-origin_godminer-new/api_new.c",
             141,
             "set_miner_start_time",
             20,
             352,
             60,
             v5);
  }
  return result;
}
