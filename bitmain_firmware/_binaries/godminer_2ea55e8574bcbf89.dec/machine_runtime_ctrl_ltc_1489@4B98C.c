void *machine_runtime_ctrl_ltc_1489()
{
  void *v0; // r0
  void *v1; // r8
  _DWORD v3[28]; // [sp+10h] [bp-1070h] BYREF
  char v4[4096]; // [sp+80h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v4, 0x1000u, 0, "machine_runtime_ctrl_ltc_1489() in");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/machine_runtime/ltc_1489/machine_runtime_ltc_1498.c",
    183,
    "machine_runtime_ctrl_ltc_1489",
    29,
    39,
    40,
    v4);
  memset(&v3[4], 0, 0x5Cu);
  v0 = calloc(1u, 0x70u);
  v1 = v0;
  if ( v0 )
  {
    v3[1] = sub_4B81C;
    v3[0] = nullsub_1;
    v3[2] = get_working_voltage_base;
    v3[3] = start_voltage_monitor_base;
    v3[8] = set_baud_base;
    v3[7] = set_voltage_base;
    v3[9] = set_frequency_with_voltage_base;
    v3[10] = start_mining_base;
    v3[12] = reset_mining_base;
    v3[11] = stop_mining_base;
    v3[13] = check_asic_num_base;
    v3[14] = check_bringup_temperature_base;
    v3[19] = 3000000;
    v3[18] = "aw";
    v3[22] = 1680;
    v3[27] = "/config/sn";
    memcpy(v0, v3, 0x70u);
    V_LOCK();
    logfmt_raw(v4, 0x1000u, 0, "machine_runtime_ctrl_ltc_1489() out");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/ltc_1489/machine_runtime_ltc_1498.c",
      183,
      "machine_runtime_ctrl_ltc_1489",
      29,
      69,
      40,
      v4);
  }
  else
  {
    printf(aInvalidPointer, "new_machine_runtime");
  }
  return v1;
}
