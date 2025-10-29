int singleBoardTest_Z15_BM1746()
{
  char tmp42[1024]; // [sp+8h] [bp+0h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "Start %s[%d]\n", "singleBoardTest_Z15_BM1746", 676);
    applog(2, tmp42, 0);
  }
  init_pcba_args();
  pthread_create(&cgpu.show_id, 0, (void *(*)(void *))show_stats_func_z15_3chips, 0);
  init_fpga();
  set_fpga_baud(0x1Au);
  check_chain();
  if ( gChain == 255 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "--- Chain Check Fail\n");
      applog(2, tmp42, 0);
    }
    return -1;
  }
  else
  {
    reset_PIC16F1704_pic(gChain, gI2c);
    jump_from_loader_to_app_PIC16F1704(gChain, gI2c);
    pthread_create(&cgpu.pic_heart_beat_id, 0, (void *(*)(void *))pic_heart_beat_func, &chain_info_0[gChain]);
    write_axi_fpga(0xDu, 0xFFFFu);
    usleep((__useconds_t)&buf_7545[4072]);
    enable_PIC16F1704_dc_dc(gChain, gI2c, 1u);
    usleep((__useconds_t)&buf_7545[4072]);
    write_axi_fpga(0xDu, 0);
    vol_init(app_conf->pcba_voltage);
    usleep((__useconds_t)&buf_7545[4072]);
    start_single_board_test();
    pthread_cancel(cgpu.show_id);
    pthread_join(cgpu.show_id, 0);
    V9_print_lcd_type(hardware_exception);
    write_axi_fpga(0xDu, 0xFFFFu);
    usleep((__useconds_t)&buf_7545[4072]);
    write_axi_fpga(0xDu, 0);
    usleep((__useconds_t)&buf_7545[4072]);
    enable_PIC16F1704_dc_dc(gChain, gI2c, 0);
    pthread_mutex_lock(&i2c_mutex);
    pthread_cancel(cgpu.pic_heart_beat_id);
    pthread_join(cgpu.pic_heart_beat_id, 0);
    pthread_mutex_unlock(&i2c_mutex);
    clear_last_test_results();
    fan_control(2u);
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "Test finished\n");
      applog(2, tmp42, 0);
    }
    return 1;
  }
}
