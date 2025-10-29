void __cdecl pcba_runtime_init(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  int bt8d; // [sp+408h] [bp+408h]
  int chainid; // [sp+40Ch] [bp+40Ch]

  chainid = runtime->chain_id;
  runtime->chain_status[chainid].design_asic_num = app_conf->asic_num;
  reg_list_init();
  work_list_init(runtime->nonce_verify_info.work_len);
  runtime->chain_status[chainid].fd = uart_init(runtime->chain_status[chainid].comport, 115200);
  sleep(1u);
  if ( runtime->baudrate != 115200 )
  {
    bt8d = baud2bt8d(runtime->baudrate);
    if ( bt8d <= 0 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        strcpy(tmp42, "Don't support current baudrate, set to 115200\n");
        applog(2, tmp42, 0);
      }
    }
    else
    {
      runtime->set_baud(runtime->chain_status[chainid].fd, runtime->baudrate);
      usleep(0x30D40u);
      set_fpga_baud(bt8d);
      sleep(1u);
    }
  }
  pthread_create(&runtime->chain_status[chainid].p_dispatch, 0, (void *(*)(void *))handle_asic_response, runtime);
  sleep(1u);
  pthread_create(&runtime->p_scanhash, 0, (void *(*)(void *))check_nonce_loop, runtime);
  runtime->start_recv = 1;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s Done!\n", "pcba_runtime_init");
    applog(2, tmp42, 0);
  }
}
