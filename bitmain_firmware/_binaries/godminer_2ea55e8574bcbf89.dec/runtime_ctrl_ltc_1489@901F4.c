void *runtime_ctrl_ltc_1489()
{
  void *v0; // r0
  void *v2; // [sp+14h] [bp-13D0h]
  _QWORD v3[121]; // [sp+18h] [bp-13CCh] BYREF
  char v4[4100]; // [sp+3E0h] [bp-1004h] BYREF

  V_LOCK();
  logfmt_raw(v4, 0x1000u, 0, "runtime_ctrl_ltc() in");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_ltc_1489/backend_ltc_1489.c",
    175,
    "runtime_ctrl_ltc_1489",
    21,
    957,
    40,
    v4);
  memset(v3, 0, sizeof(v3));
  LODWORD(v3[34]) = 14156;
  HIDWORD(v3[42]) = 210;
  LODWORD(v3[43]) = 500;
  LODWORD(v3[36]) = 6517868;
  HIDWORD(v3[44]) = sensor_info_ltc_1489;
  v3[45] = qword_171A5C;
  v3[46] = qword_171A64;
  v3[47] = qword_171A6C;
  v0 = calloc(1u, 0x3C8u);
  LODWORD(v3[2]) = dhash_mining_start_base;
  HIDWORD(v3[2]) = dhash_mining_stop_base;
  LODWORD(v3[3]) = dhash_mining_reset_base;
  HIDWORD(v3[3]) = backend_exit_base;
  LODWORD(v3[4]) = push_work_base;
  HIDWORD(v3[4]) = async_push_work_base;
  LODWORD(v3[5]) = pop_ans_base;
  HIDWORD(v3[5]) = try_pop_ans_base;
  LODWORD(v3[7]) = softreset_all_chip_ltc;
  HIDWORD(v3[7]) = setup_all_chip_ltc;
  LODWORD(v3[8]) = work_2_packet_ltc;
  HIDWORD(v3[8]) = packet_2_nonce_ltc;
  LODWORD(v3[9]) = check_nonce_ltc;
  HIDWORD(v3[9]) = global_idx_init_ltc;
  LODWORD(v3[10]) = global_idx_free_ltc;
  HIDWORD(v3[10]) = set_baud_ltc;
  LODWORD(v3[11]) = sub_8E700;
  HIDWORD(v3[11]) = sub_8E5E4;
  LODWORD(v3[12]) = sub_8C8D8;
  HIDWORD(v3[12]) = sub_8C348;
  LODWORD(v3[13]) = sub_8C350;
  HIDWORD(v3[13]) = sub_8E310;
  LODWORD(v3[14]) = sub_8D6CC;
  HIDWORD(v3[14]) = sub_8DF3C;
  LODWORD(v3[15]) = sub_8DF14;
  LODWORD(v3[16]) = get_chip_status_ltc;
  v2 = v0;
  LODWORD(v3[0]) = backend_init_base;
  HIDWORD(v3[0]) = reset_base;
  HIDWORD(v3[16]) = get_theory_hashrate_ltc;
  LODWORD(v3[17]) = get_sale_hashrate_ltc;
  HIDWORD(v3[17]) = get_qualify_hashrate_ltc;
  LODWORD(v3[18]) = get_qualify_nonce_num_ltc;
  HIDWORD(v3[18]) = set_sensor_extern_mode_ltc;
  LODWORD(v3[19]) = read_sensor_temp_local_ltc;
  HIDWORD(v3[20]) = overclock_update_ltc;
  HIDWORD(v3[19]) = read_sensor_temp_remote_ltc;
  HIDWORD(v3[21]) = get_packet_remain_len_ltc;
  LODWORD(v3[23]) = adjust_working_freq_ltc;
  LODWORD(v3[21]) = get_pcba_test_level_ltc;
  HIDWORD(v3[25]) = sub_8C8F0;
  LODWORD(v3[26]) = top_init_ltc;
  HIDWORD(v3[23]) = sub_8DB48;
  LODWORD(v3[20]) = parameter_update_ltc;
  HIDWORD(v3[29]) = set_inactive_base;
  LODWORD(v3[30]) = set_chip_reg_ltc;
  LODWORD(v3[27]) = dhash_start_ltc;
  HIDWORD(v3[24]) = sub_8EC84;
  HIDWORD(v3[32]) = sync_get_chip_reg_ltc;
  HIDWORD(v3[33]) = sync_get_core_reg_ltc;
  HIDWORD(v3[31]) = set_core_enable_ltc;
  v3[37] = 0x100001489LL;
  v3[38] = 0x7500000078LL;
  LODWORD(v3[29]) = set_chipaddr_base;
  v3[39] = 0x8000003A8LL;
  LODWORD(v3[50]) = 27;
  HIDWORD(v3[98]) = 216;
  HIDWORD(v3[30]) = set_core_reg_ltc;
  LODWORD(v3[31]) = set_core_reg_ltc;
  HIDWORD(v3[40]) = 2;
  HIDWORD(v3[49]) = 2;
  LODWORD(v3[32]) = sync_get_status_ltc;
  HIDWORD(v3[61]) = 2;
  v3[99] = 0x400000070LL;
  LODWORD(v3[119]) = 1;
  v3[118] = 949793;
  v3[100] = 0x900000056LL;
  LODWORD(v3[101]) = 8;
  v3[115] = 0x44D1600042480000LL;
  LODWORD(v3[116]) = 1500;
  memcpy(v0, v3, 0x3C8u);
  V_LOCK();
  logfmt_raw(v4, 0x1000u, 0, "runtime_ctrl_ltc() out");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_ltc_1489/backend_ltc_1489.c",
    175,
    "runtime_ctrl_ltc_1489",
    21,
    1060,
    40,
    v4);
  return v2;
}
