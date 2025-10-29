int __fastcall set_check_asic_voltage(int a1)
{
  int result; // r0
  char v3[4100]; // [sp+10h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v3, 0x1000u, 0, "set_check_asic_voltage");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "set_check_asic_voltage",
    22,
    549,
    40,
    v3);
  if ( a1 )
    result = set_voltage_by_steps(dword_17421C, (unsigned __int8)byte_174208);
  else
    result = set_voltage(dword_17421C, (unsigned __int8)byte_174208);
  if ( result )
  {
    V_LOCK();
    logfmt_raw(v3, 0x1000u, 0, "set_check_asic_voltage error!");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/power_api.c",
      154,
      "set_check_asic_voltage",
      22,
      557,
      100,
      v3);
    return -1;
  }
  return result;
}
