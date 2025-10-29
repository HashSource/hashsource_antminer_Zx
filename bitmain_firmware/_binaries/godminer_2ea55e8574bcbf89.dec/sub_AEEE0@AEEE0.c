int sub_AEEE0()
{
  char s[2048]; // [sp+10h] [bp-1804h] BYREF
  char v2[4100]; // [sp+810h] [bp-1004h] BYREF

  snprintf(s, 0x800u, "%s: g_eeprom_data is not ready", "eeprom_get_fmt_version");
  V_LOCK();
  logfmt_raw(v2, 0x1000u, 0, s);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/device/hal/eeprom/bitmain_eeprom.c",
    174,
    "eeprom_get_fmt_version",
    22,
    1109,
    100,
    v2);
  return -1;
}
