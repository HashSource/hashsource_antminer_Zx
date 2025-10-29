int __cdecl user_asic_init(runtime_base_t *runtime)
{
  int v2; // r0
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  int chainid; // [sp+408h] [bp+408h]
  int check_times; // [sp+40Ch] [bp+40Ch]

  chainid = runtime->chain_id;
  for ( check_times = 3; check_times > 0; --check_times )
  {
    check_asic_num(runtime);
    if ( runtime->chain_status[chainid].real_asic_num > 0 )
      break;
    sleep(1u);
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "check again check_times = %d\n", check_times);
      applog(2, tmp42, 0);
    }
  }
  if ( check_times > 0 )
  {
    runtime->start_recv = 0;
    if ( runtime->baudrate != 115200 )
    {
      sleep(1u);
      runtime->set_baud(runtime->chain_status[chainid].fd, runtime->baudrate);
      sleep(1u);
      uart_close(runtime->chain_status[chainid].fd);
      sleep(1u);
      v2 = uart_init(runtime->chain_status[chainid].comport, runtime->baudrate);
      runtime->chain_status[chainid].fd = v2;
      sleep(1u);
    }
    runtime->start_recv = 1;
    return 0;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      strcpy(tmp42, "check asic failed\n");
      applog(0, tmp42, 0);
    }
    return -1;
  }
}
