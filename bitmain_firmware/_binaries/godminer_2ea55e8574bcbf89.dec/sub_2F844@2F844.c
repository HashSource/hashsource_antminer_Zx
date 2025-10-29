_DWORD *__fastcall sub_2F844(char *s2)
{
  _DWORD *result; // r0
  char v3[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( dword_173210[0] > 0x13u )
  {
    V_LOCK();
    logfmt_raw(v3, 0x1000u, 0, "only support %d reject reasons", dword_173210[0]);
    V_UNLOCK();
    return (_DWORD *)zlog(
                       g_zc,
                       "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/"
                       "build/godminer-origin_godminer-new/pool.c",
                       138,
                       "reject_reason_history_update",
                       28,
                       41,
                       20,
                       v3);
  }
  else
  {
    if ( !dword_173210[0] )
    {
      V_LOCK();
      logfmt_raw(v3, 0x1000u, 0, "reject reason init %d", dword_173210[0]);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/pool.c",
        138,
        "reject_reason_history_update",
        28,
        46,
        40,
        v3);
      reject_reason_map = 0;
      dword_186A5C = 0;
      dword_186A60 = 0;
      dword_186A64 = 0;
      dword_186A68 = 0;
    }
    result = (_DWORD *)map_get_(&reject_reason_map, s2);
    dword_186A64 = (int)result;
    if ( result )
    {
      ++*result;
    }
    else
    {
      dword_186A68 = 1;
      ++dword_173210[0];
      return (_DWORD *)map_set_((void **)&reject_reason_map, s2, &dword_186A68, 4u);
    }
  }
  return result;
}
