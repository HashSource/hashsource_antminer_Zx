void *runtime_ctrl_rvn_2020()
{
  void *v0; // r0
  void *v1; // r4
  _QWORD v3[121]; // [sp+0h] [bp-3CCh] BYREF

  memset(v3, 0, sizeof(v3));
  LODWORD(v3[34]) = 5133906;
  LODWORD(v3[36]) = 7239282;
  HIDWORD(v3[42]) = 500;
  LODWORD(v3[43]) = 500;
  v0 = calloc(1u, 0x3C8u);
  LODWORD(v3[0]) = backend_init_base;
  HIDWORD(v3[0]) = reset_base;
  HIDWORD(v3[1]) = set_dag_node_num_rvn;
  LODWORD(v3[2]) = dhash_mining_start_rvn;
  LODWORD(v3[3]) = recover_mining_rvn;
  HIDWORD(v3[3]) = backend_exit_base;
  HIDWORD(v3[4]) = async_push_work_base;
  LODWORD(v3[5]) = pop_ans_base;
  LODWORD(v3[7]) = softreset_all_chip_rvn;
  LODWORD(v3[8]) = work_2_packet_rvn;
  LODWORD(v3[9]) = check_nonce_rvn;
  HIDWORD(v3[9]) = global_idx_init_rvn;
  LODWORD(v3[10]) = global_idx_free_rvn;
  HIDWORD(v3[10]) = set_baud_rvn;
  LODWORD(v3[15]) = sub_91FA8;
  LODWORD(v3[16]) = get_chip_status_rvn;
  HIDWORD(v3[16]) = get_theory_hashrate_rvn;
  LODWORD(v3[17]) = get_sale_hashrate_rvn;
  HIDWORD(v3[17]) = get_qualify_hashrate_rvn;
  LODWORD(v3[1]) = change_kiss99_param_rvn;
  LODWORD(v3[18]) = get_qualify_nonce_num_rvn;
  HIDWORD(v3[18]) = set_sensor_extern_mode_rvn;
  HIDWORD(v3[2]) = stop_mining_rvn;
  LODWORD(v3[19]) = read_sensor_temp_local_rvn;
  HIDWORD(v3[19]) = read_sensor_temp_remote_rvn;
  LODWORD(v3[4]) = push_work_base;
  LODWORD(v3[20]) = parameter_update_rvn;
  HIDWORD(v3[20]) = overclock_update_rvn;
  HIDWORD(v3[5]) = try_pop_ans_base;
  LODWORD(v3[21]) = get_pcba_test_level_rvn;
  HIDWORD(v3[21]) = get_packet_remain_len_rvn;
  HIDWORD(v3[8]) = packet_2_nonce_rvn;
  HIDWORD(v3[23]) = set_frequency_rvn;
  HIDWORD(v3[24]) = sub_92FE8;
  LODWORD(v3[26]) = top_init_rvn;
  HIDWORD(v3[25]) = read_temperature_rvn;
  LODWORD(v3[29]) = set_chipaddr_base;
  LODWORD(v3[30]) = set_chip_reg_base;
  LODWORD(v3[31]) = set_core_reg_base2;
  LODWORD(v3[27]) = dhash_start_rvn;
  LODWORD(v3[32]) = sync_get_status_base2;
  HIDWORD(v3[29]) = set_inactive_base;
  LODWORD(v3[33]) = sync_get_dag_node_base;
  HIDWORD(v3[30]) = set_core_reg_rvn;
  HIDWORD(v3[44]) = &sensor_rvn_bm2020;
  HIDWORD(v3[31]) = set_core_enable_base2;
  v3[38] = 0x800000008LL;
  HIDWORD(v3[45]) = 8;
  v3[37] = 0x100002020LL;
  v3[47] = 0x3FFFFFFECLL;
  HIDWORD(v3[32]) = sync_get_chip_reg_base2;
  LODWORD(v3[50]) = 9;
  v3[46] = 0x500000005FLL;
  v3[99] = 0x800000082LL;
  HIDWORD(v3[33]) = sync_get_core_reg_base2;
  HIDWORD(v3[98]) = 89;
  v1 = v0;
  HIDWORD(v3[57]) = 1;
  v3[100] = 0x2B0000002ELL;
  v3[115] = 0x4448000044480000LL;
  v3[118] = 1000000;
  LODWORD(v3[119]) = 1;
  memcpy(v0, v3, 0x3C8u);
  return v1;
}
