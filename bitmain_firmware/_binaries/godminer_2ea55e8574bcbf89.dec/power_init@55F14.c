int __fastcall power_init(int a1, int a2)
{
  double v2; // d0
  int v4; // r8
  int is_pic_mcu_en; // r7
  unsigned __int16 v6; // r0
  int v8; // r7
  int v9; // r9
  bool v10; // zf
  unsigned int v11; // r8
  int v12; // r11
  double v13; // d9
  int v14; // r10
  double v15; // d8
  int device_num; // r0
  double v17; // d14
  int v18; // r6
  int v19; // r0
  int v20; // r0
  int v21; // r0
  int v22; // r0
  int v23; // r0
  int v24; // r0
  int j; // r5
  int v26; // r0
  int v27; // r0
  int k; // r5
  int v29; // r0
  int v30; // r0
  int m; // r5
  int v32; // r0
  int v33; // r0
  int n; // r5
  int v35; // r0
  int v36; // r0
  int v37; // r0
  double v38; // d14
  int v39; // r3
  int v40; // r2
  int v41; // r12
  double v42; // d8
  int v43; // r7
  int chain_num; // r11
  int v45; // r6
  int v46; // r9
  int i; // r5
  int v48; // r0
  int v49; // [sp+4h] [bp-1028h]
  int v50; // [sp+4h] [bp-1028h]
  int v51; // [sp+4h] [bp-1028h]
  int v52; // [sp+1Ch] [bp-1010h]
  int v53; // [sp+24h] [bp-1008h] BYREF
  char v54[4100]; // [sp+28h] [bp-1004h] BYREF

  v53 = a2;
  get_all_created_runtime(&v53);
  if ( !platform_is_adjustable_power() )
  {
    V_LOCK();
    logfmt_raw(v54, 0x1000u, 0, "%s, current algo donot use adjustable power!", "power_init");
    V_UNLOCK();
    is_pic_mcu_en = -1;
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/power_api.c",
      154,
      "power_init",
      10,
      296,
      100,
      v54);
    V_LOCK();
    logfmt_raw(v54, 0x1000u, 0, "Sweep error string = %s.", "V:2");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/power_api.c",
      154,
      "power_init",
      10,
      297,
      100,
      v54);
    return is_pic_mcu_en;
  }
  v4 = (unsigned __int16)bitmain_power_version();
  if ( !platform_is_psu_supported(v4) )
  {
    V_LOCK();
    logfmt_raw(v54, 0x1000u, 0, "Not support power version, %04x", v4);
    V_UNLOCK();
    is_pic_mcu_en = -1;
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/power_api.c",
      154,
      "power_init",
      10,
      303,
      100,
      v54);
    return is_pic_mcu_en;
  }
  is_pic_mcu_en = platform_is_pic_mcu_en();
  if ( !is_pic_mcu_en )
  {
    v6 = bitmain_set_watchdog(0);
    v4 = v6;
    if ( v6 )
    {
      V_LOCK();
      logfmt_raw(v54, 0x1000u, 0, "disable power watchdog: %04x", v4);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/miner_util/power_api.c",
        154,
        "power_init",
        10,
        310,
        100,
        v54);
      return is_pic_mcu_en;
    }
    sleep(1u);
  }
  bitmain_power_off();
  byte_174220 = 0;
  sleep(1u);
  if ( a1 )
  {
    fan_pwm_set(0);
    while ( 1 )
      sleep(0xAu);
  }
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "Initializing the power, please wait, this may take up 1 minute...");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    322,
    60,
    v54);
  sleep(0x3Cu);
  if ( platform_is_pic_mcu_en() )
    goto LABEL_12;
  v42 = 0.0;
  v43 = 21;
  chain_num = platform_get_chain_num();
  v45 = 1;
  v46 = 100;
  while ( 1 )
  {
    if ( chain_num > 0 )
    {
      for ( i = 0; i != chain_num; ++i )
      {
        v48 = i;
        read_feedback_voltage(v48);
        if ( v2 > v42 )
          v42 = v2;
      }
    }
    if ( v42 <= 10.0 )
      break;
    if ( v46 > 20 )
    {
      v46 = 20;
      sleep(1u);
      if ( !--v43 )
        goto LABEL_91;
LABEL_87:
      v45 = 1;
    }
    else
    {
      sleep(1u);
      if ( !--v43 )
        goto LABEL_91;
      if ( ++v45 > 19 )
        goto LABEL_12;
      v46 = 20;
    }
  }
  if ( v42 <= 4.0 )
    goto LABEL_12;
  if ( v46 != 2 )
  {
    v46 = 2;
    sleep(1u);
    if ( !--v43 )
      goto LABEL_91;
    goto LABEL_87;
  }
  sleep(1u);
  if ( v43 != 1 )
    goto LABEL_12;
LABEL_91:
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "APW discharge too slow OR pic adc wrong");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "wait_for_psu_discharge",
    22,
    187,
    100,
    v54);
LABEL_12:
  v8 = (unsigned __int16)bitmain_power_fw_version();
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "bitmain power fw version: %04x", v8);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    331,
    60,
    v54);
  byte_174221 = 0;
  dword_174224 = 0;
  dword_174228 = 0;
  byte_174208 = 1;
  if ( opt_custom_voltage_swith || is_eeprom_loaded() )
    dword_174214 = opt_custom_voltage;
  byte_17420C = platform_is_adjustable_power();
  byte_174218 = platform_is_check_asic_voltage_enable();
  dword_17421C = platfrom_get_check_asic_voltage();
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "Power init:");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    352,
    40,
    v54);
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "current_voltage_raw\t\t= %d", dword_174224);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    353,
    40,
    v54);
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "working_voltage_raw\t\t= %d", dword_174214);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    354,
    40,
    v54);
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "check_asic_voltage_enable\t= %d", (unsigned __int8)byte_174218);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    355,
    40,
    v54);
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "check_asic_voltage_raw\t= %d", dword_17421C);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    356,
    40,
    v54);
  if ( byte_17420C && byte_174218 )
    v9 = set_check_asic_voltage(0);
  else
    v9 = set_working_voltage(0);
  if ( v9 )
  {
    V_LOCK();
    is_pic_mcu_en = -1;
    logfmt_raw(v54, 0x1000u, 0, "set_voltage_by_steps error!");
    V_UNLOCK();
    v41 = 364;
LABEL_65:
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/power_api.c",
      154,
      "power_init",
      10,
      v41,
      100,
      v54);
    return is_pic_mcu_en;
  }
  v10 = v4 == 113;
  if ( v4 != 113 )
    v10 = v4 == 116;
  v11 = 0;
  if ( !v10 )
  {
    while ( 1 )
    {
      is_pic_mcu_en = bitmain_get_power_status();
      ++v11;
      if ( !is_pic_mcu_en )
        break;
      if ( v11 == 5 * (v11 / 5) )
      {
        V_LOCK();
        logfmt_raw(v54, 0x1000u, v11 % 5, ">> bitmain_get_power_status failed(%d) <<", is_pic_mcu_en);
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/miner_util/power_api.c",
          154,
          "power_init",
          10,
          378,
          100,
          v54);
      }
      sleep(3u);
      if ( v11 == 20 )
        goto LABEL_28;
    }
  }
  is_pic_mcu_en = 0;
LABEL_28:
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "bitmain_get_power_status end!");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    385,
    40,
    v54);
  bitmain_power_on();
  byte_174220 = 1;
  sleep(1u);
  if ( byte_174208 )
    v12 = dword_174224;
  else
    v12 = sub_55588();
  v13 = (double)v12;
  v14 = 3;
  v15 = (double)v12 * 0.75 / 100.0;
  while ( 2 )
  {
    sleep(1u);
    if ( platform_is_pic_mcu_en() )
    {
      device_num = query_device_num();
      v17 = 0.0;
      v52 = device_num;
      if ( device_num > 0 )
      {
        v18 = 0;
        do
        {
          v19 = dev_ctrl(device_num);
          v20 = (*(int (__fastcall **)(int))(v19 + 48))(v18);
          read_feedback_voltage(v20);
          v21 = V_LOCK();
          v22 = dev_ctrl(v21);
          v23 = (*(int (__fastcall **)(int))(v22 + 48))(v18);
          logfmt_raw(v54, 0x1000u, 0, "chain %d feedback voltage = %.2f", v23, v49, v2);
          V_UNLOCK();
          device_num = zlog(
                         g_zc,
                         "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/releas"
                         "e/build/godminer-origin_godminer-new/miner_util/power_api.c",
                         154,
                         "get_minimal_feedback_voltage",
                         28,
                         69,
                         40,
                         v54);
          if ( v2 > 0.1 )
          {
            if ( v2 >= v17 )
            {
              if ( v17 < 0.1 )
                v17 = v2;
            }
            else
            {
              v17 = v2;
            }
          }
          ++v18;
        }
        while ( v52 != v18 );
      }
      V_LOCK();
      logfmt_raw(v54, 0x1000u, 0, "the minimal voltage = %.2f", v17);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/miner_util/power_api.c",
        154,
        "get_minimal_feedback_voltage",
        28,
        74,
        20,
        v54);
      if ( v15 <= v17 )
      {
        V_LOCK();
        logfmt_raw(
          v54,
          0x1000u,
          0,
          "power voltage qualified! centi_voltage %d feedback_voltage %f qualified_vol %f",
          v12,
          v50,
          v17,
          v15);
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/miner_util/power_api.c",
          154,
          "check_feedback_voltage",
          22,
          95,
          80,
          v54);
        goto LABEL_43;
      }
      V_LOCK();
      logfmt_raw(
        v54,
        0x1000u,
        0,
        "power voltage can not meet the target! centi_voltage %d feedback_voltage %f qualified_vol %f",
        v12,
        v50,
        v17,
        v15);
      V_UNLOCK();
      v39 = 80;
      v40 = 91;
      goto LABEL_63;
    }
    read_feedback_voltage(0);
    V_LOCK();
    logfmt_raw(v54, 0x1000u, 0, "read fb voltage %.2f", v2);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/miner_util/power_api.c",
      154,
      "check_feedback_voltage",
      22,
      100,
      20,
      v54);
    if ( v2 >= 0.0 )
    {
      v38 = v2 * 100.0;
      if ( v2 * 100.0 <= v13 * 1.1 && v38 >= v13 * 0.9 )
        goto LABEL_43;
      V_LOCK();
      logfmt_raw(v54, 0x1000u, 0, "power voltage qualified! centi_voltage %d fb_vol %f", v12, v51, v38);
      V_UNLOCK();
      v39 = 100;
      v40 = 107;
LABEL_63:
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/miner_util/power_api.c",
        154,
        "check_feedback_voltage",
        22,
        v40,
        v39,
        v54);
      if ( !--v14 )
      {
        V_LOCK();
        is_pic_mcu_en = -1;
        logfmt_raw(v54, 0x1000u, 0, "check_feedback_voltage error!");
        V_UNLOCK();
        v41 = 407;
        goto LABEL_65;
      }
      continue;
    }
    break;
  }
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "read_feedback_voltage_from_psu failed!");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "check_feedback_voltage",
    22,
    102,
    80,
    v54);
LABEL_43:
  V_LOCK();
  logfmt_raw(v54, 0x1000u, 0, "check_feedback_voltage end!");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/miner_util/power_api.c",
    154,
    "power_init",
    10,
    412,
    40,
    v54);
  if ( opt_algo == 11 )
  {
    v24 = usleep((__useconds_t)&stru_1869C.st_value);
    if ( v53 > 0 )
    {
      for ( j = 0; j < v53; ++j )
      {
        v26 = dev_ctrl(v24);
        v24 = (*(int (__fastcall **)(int))(v26 + 36))(j);
      }
    }
    v27 = usleep((__useconds_t)&stru_1869C.st_value);
    if ( v53 > 0 )
    {
      for ( k = 0; k < v53; ++k )
      {
        v29 = dev_ctrl(v27);
        v27 = (*(int (__fastcall **)(int))(v29 + 40))(k);
      }
    }
    v30 = usleep((__useconds_t)&stru_1869C.st_value);
    if ( v53 > 0 )
    {
      for ( m = 0; m < v53; ++m )
      {
        v32 = dev_ctrl(v30);
        v30 = (*(int (__fastcall **)(int))(v32 + 36))(m);
      }
    }
    v33 = usleep((__useconds_t)&stru_1869C.st_value);
    if ( v53 > 0 )
    {
      for ( n = 0; n < v53; ++n )
      {
        v35 = dev_ctrl(v33);
        v33 = (*(int (__fastcall **)(int))(v35 + 40))(n);
      }
    }
    v36 = usleep((__useconds_t)&stru_1869C.st_value);
    if ( v53 > 0 )
    {
      do
      {
        v37 = dev_ctrl(v36);
        v36 = (*(int (__fastcall **)(int))(v37 + 36))(v9++);
      }
      while ( v53 > v9 );
    }
  }
  return is_pic_mcu_en;
}
