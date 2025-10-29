void *runtime_ctrl_eth_2280()
{
  void *v0; // r0
  void *v1; // r4
  _QWORD v3[121]; // [sp+0h] [bp-3CCh] BYREF

  memset(v3, 0, sizeof(v3));
  strcpy((char *)&v3[34], "E9 Pro");
  HIDWORD(v3[42]) = 500;
  LODWORD(v3[43]) = 500;
  *(_DWORD *)((char *)&v3[34] + 7) = 0;
  *(_DWORD *)((char *)&v3[35] + 3) = 0;
  HIBYTE(v3[35]) = 0;
  LODWORD(v3[36]) = 6845541;
  v0 = calloc(1u, 0x3C8u);
  HIDWORD(v3[0]) = reset_base;
  LODWORD(v3[2]) = dhash_mining_start_base;
  LODWORD(v3[3]) = recover_mining_eth;
  HIDWORD(v3[3]) = backend_exit_base;
  HIDWORD(v3[4]) = async_push_work_base;
  LODWORD(v3[5]) = pop_ans_base;
  LODWORD(v3[7]) = softreset_all_chip_eth;
  LODWORD(v3[8]) = work_2_packet_eth;
  LODWORD(v3[9]) = check_nonce_eth;
  HIDWORD(v3[9]) = global_idx_init_eth;
  LODWORD(v3[10]) = global_idx_free_eth;
  HIDWORD(v3[10]) = set_baud_eth;
  LODWORD(v3[15]) = sub_6F2C0;
  HIDWORD(v3[15]) = set_ticketmask;
  LODWORD(v3[16]) = get_chip_status_eth;
  HIDWORD(v3[16]) = get_theory_hashrate_eth;
  LODWORD(v3[17]) = get_sale_hashrate_eth;
  HIDWORD(v3[17]) = get_qualify_hashrate_eth;
  LODWORD(v3[0]) = backend_init_base;
  LODWORD(v3[18]) = get_qualify_nonce_num_eth;
  HIDWORD(v3[18]) = set_sensor_extern_mode_eth;
  HIDWORD(v3[2]) = stop_mining_eth;
  LODWORD(v3[19]) = read_sensor_temp_local_eth;
  HIDWORD(v3[19]) = read_sensor_temp_remote_eth;
  LODWORD(v3[4]) = push_work_base;
  LODWORD(v3[20]) = parameter_update_eth;
  HIDWORD(v3[20]) = overclock_update_eth;
  HIDWORD(v3[5]) = try_pop_ans_base;
  LODWORD(v3[21]) = get_pcba_test_level_eth;
  HIDWORD(v3[21]) = get_packet_remain_len_eth;
  HIDWORD(v3[8]) = packet_2_nonce_eth;
  HIDWORD(v3[23]) = set_frequency_eth;
  HIDWORD(v3[24]) = sub_70B3C;
  LODWORD(v3[26]) = top_init_eth;
  HIDWORD(v3[25]) = read_temperature_eth;
  LODWORD(v3[29]) = set_chipaddr_base;
  LODWORD(v3[27]) = dhash_start_eth;
  LODWORD(v3[30]) = set_chip_reg_base;
  HIDWORD(v3[29]) = set_inactive_base;
  HIDWORD(v3[32]) = sync_get_chip_reg_base2;
  HIDWORD(v3[30]) = set_core_reg_base2;
  LODWORD(v3[31]) = set_core_reg_base2;
  HIDWORD(v3[33]) = sync_get_core_reg_base2;
  LODWORD(v3[32]) = sync_get_status_base2;
  v3[38] = 0x1000000008LL;
  HIDWORD(v3[45]) = 8;
  HIDWORD(v3[31]) = set_core_enable_base2;
  LODWORD(v3[33]) = sync_get_dag_node_base;
  v3[115] = 0x43FA000043FA0000LL;
  v3[37] = 0x100002280LL;
  v3[47] = 0x3FFFFFFECLL;
  v3[46] = 0x500000005FLL;
  HIDWORD(v3[98]) = 89;
  v1 = v0;
  HIDWORD(v3[44]) = &sensor_eth_bm2280;
  LODWORD(v3[50]) = 32;
  HIDWORD(v3[57]) = 1;
  v3[100] = 0x2B0000002ELL;
  v3[99] = 0x800000082LL;
  v3[118] = 1000000;
  LODWORD(v3[119]) = 1;
  memcpy(v0, v3, 0x3C8u);
  return v1;
}
