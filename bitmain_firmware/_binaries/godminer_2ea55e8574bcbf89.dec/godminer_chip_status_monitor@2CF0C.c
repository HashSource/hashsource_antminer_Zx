pthread_mutex_t *__fastcall godminer_chip_status_monitor(int a1)
{
  char *flag_from_monitor; // r4
  pthread_mutex_t *result; // r0
  int v4; // r1
  pthread_mutex_t *v5; // r5
  _DWORD v6[7]; // [sp+28h] [bp-1040h] BYREF
  int v7; // [sp+44h] [bp-1024h]
  _DWORD v8[7]; // [sp+48h] [bp-1020h] BYREF
  int v9; // [sp+64h] [bp-1004h]
  char v10[4096]; // [sp+68h] [bp-1000h] BYREF

  flag_from_monitor = get_flag_from_monitor(a1);
  result = (pthread_mutex_t *)get_current_pool();
  v4 = *((_DWORD *)flag_from_monitor + 12);
  v5 = result;
  if ( (v4 & 2) != 0 )
  {
    result = (pthread_mutex_t *)pool_tget(result, (unsigned __int8 *)&result[79].__size[8]);
    if ( !result )
    {
      V_LOCK();
      V_INT((int)v6, "chain", *(int *)(a1 + 224));
      logfmt_raw(v10, 0x1000u, 0, v7, v6[0], v6[1], v6[2], v6[3], v6[4], v6[5], v6[6], v7, "some chip not working");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/god-miner.c",
        143,
        "godminer_chip_status_monitor",
        28,
        707,
        20,
        v10);
      set_miner_6060info_some_chip_not_working_err(*(_DWORD *)(a1 + 224), 1);
      V_LOCK();
      logfmt_raw(v10, 0x1000u, 0, "Sweep error string = J%d:1.", *(_DWORD *)(a1 + 224));
      V_UNLOCK();
      result = (pthread_mutex_t *)zlog(
                                    g_zc,
                                    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot"
                                    "/tmp/release/build/godminer-origin_godminer-new/god-miner.c",
                                    143,
                                    "godminer_chip_status_monitor",
                                    28,
                                    709,
                                    100,
                                    v10);
    }
    v4 = *((_DWORD *)flag_from_monitor + 12);
    *((_DWORD *)flag_from_monitor + 14) |= 2u;
  }
  if ( (v4 & 4) != 0 )
  {
    result = (pthread_mutex_t *)pool_tget(v5, (unsigned __int8 *)&v5[79].__size[8]);
    if ( !result )
    {
      V_LOCK();
      V_INT((int)v8, "chain", *(int *)(a1 + 224));
      logfmt_raw(v10, 0x1000u, 0, v9, v8[0], v8[1], v8[2], v8[3], v8[4], v8[5], v8[6], v9, "some chip working slow");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/god-miner.c",
        143,
        "godminer_chip_status_monitor",
        28,
        723,
        20,
        v10);
      V_LOCK();
      logfmt_raw(v10, 0x1000u, 0, "Sweep error string = J%d:1.", *(_DWORD *)(a1 + 224));
      V_UNLOCK();
      result = (pthread_mutex_t *)zlog(
                                    g_zc,
                                    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot"
                                    "/tmp/release/build/godminer-origin_godminer-new/god-miner.c",
                                    143,
                                    "godminer_chip_status_monitor",
                                    28,
                                    724,
                                    100,
                                    v10);
    }
    *((_DWORD *)flag_from_monitor + 14) |= 4u;
  }
  return result;
}
