int __fastcall bitmain_set_voltage_by_n(__int16 a1)
{
  int v2; // r5
  char s[2048]; // [sp+10h] [bp-1804h] BYREF
  char v5[4100]; // [sp+810h] [bp-1004h] BYREF

  if ( dword_185764 )
    return sub_B3320((void *)dword_185760, a1);
  v2 = sub_B370C();
  if ( v2 >= 0 )
    return sub_B3320((void *)dword_185760, a1);
  snprintf(s, 0x800u, "%s: auto exec bitmain_power_open, but open power failed", "bitmain_set_voltage_by_n");
  V_LOCK();
  logfmt_raw(v5, 0x1000u, 0, s);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
    177,
    "bitmain_set_voltage_by_n",
    24,
    721,
    100,
    v5);
  return v2;
}
