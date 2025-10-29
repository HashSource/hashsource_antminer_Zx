int psu_watchdog()
{
  double v0; // d0
  int v1; // r5
  int v2; // r7
  int v3; // r5
  int current_voltage; // r6
  double v5; // d12
  double v6; // d13
  const char *v7; // r1
  int v8; // r0
  int v9; // r12
  int v10; // r2
  int power_status; // r6
  int v12; // r5
  int result; // r0
  bool v14; // zf
  int v15; // [sp+4h] [bp-1010h]
  char v16[4100]; // [sp+10h] [bp-1004h] BYREF

  v1 = bitmain_set_watchdog(1);
  V_LOCK();
  logfmt_raw(v16, 0x1000u, 0, "enable power watchdog: 0x%04x", v1);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/check_heartbeat.c",
    160,
    "psu_watchdog",
    12,
    77,
    60,
    v16);
  if ( v1 != 1 )
  {
    V_LOCK();
    logfmt_raw(v16, 0x1000u, 0, "%s enable power watchdog failed!", "psu_watchdog");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/check_heartbeat.c",
      160,
      "psu_watchdog",
      12,
      79,
      100,
      v16);
    return 0;
  }
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    pthread_setcancelstate(1, 0);
    read_feedback_voltage(0);
    current_voltage = get_current_voltage();
    if ( !is_power_on() )
      goto LABEL_15;
    if ( v0 < 0.0 )
    {
      V_LOCK();
      ++v2;
      logfmt_raw(v16, 0x1000u, 0, ">> read_feedback_voltage failed!, pls check <<");
      V_UNLOCK();
      v8 = g_zc;
      v9 = 100;
      v10 = 89;
LABEL_13:
      zlog(
        v8,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/miner_util/check_heartbeat.c",
        160,
        "psu_watchdog",
        12,
        v10,
        v9,
        v16);
      goto LABEL_14;
    }
    v5 = (double)current_voltage;
    v6 = v0 * 100.0;
    if ( v0 * 100.0 > (double)current_voltage * 1.1 || v6 < v5 * 0.9 )
    {
      V_LOCK();
      v7 = "rise";
      ++v2;
      if ( v6 - v5 <= 0.0 )
        v7 = "drop";
      logfmt_raw(v16, 0x1000u, 0, ">> chain avg vol %s from %d to %.2f, pls check <<", v7, current_voltage, v0 * 100.0);
      V_UNLOCK();
      v8 = g_zc;
      v9 = 80;
      v10 = 93;
      goto LABEL_13;
    }
    v2 = 0;
LABEL_14:
    V_LOCK();
    logfmt_raw(v16, 0x1000u, 0, "cur_voltage = %d, avg_voltage = %.2f", current_voltage, v15, v0 * 100.0);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/check_heartbeat.c",
      160,
      "psu_watchdog",
      12,
      99,
      20,
      v16);
LABEL_15:
    power_status = bitmain_get_power_status();
    if ( !power_status )
      break;
    V_LOCK();
    v12 = v3 + 1;
    logfmt_raw(v16, 0x1000u, 0, ">> power status error, ret %d, err_times %d <<", power_status, v12);
    V_UNLOCK();
    result = zlog(
               g_zc,
               "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/go"
               "dminer-origin_godminer-new/miner_util/check_heartbeat.c",
               160,
               "psu_watchdog",
               12,
               106,
               80,
               v16);
    v14 = v12 == 3;
    if ( v12 <= 3 )
      v14 = v2 == 0;
    if ( !v14 )
      return result;
    power_status = v12;
LABEL_4:
    v3 = power_status;
    pthread_setcancelstate(0, 0);
    pthread_testcancel();
    sleep(0xAu);
  }
  if ( v2 <= 3 )
    goto LABEL_4;
  V_LOCK();
  logfmt_raw(v16, 0x1000u, 0, ">> feedback voltage: too many times error, pls check <<");
  V_UNLOCK();
  return zlog(
           g_zc,
           "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmin"
           "er-origin_godminer-new/miner_util/check_heartbeat.c",
           160,
           "psu_watchdog",
           12,
           113,
           100,
           v16);
}
