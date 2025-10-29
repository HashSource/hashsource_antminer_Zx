void __cdecl pcba_runtime_exit(runtime_base_t *runtime)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF

  runtime->start_recv = 0;
  usleep((__useconds_t)&nonce_fifo.nonce_buffer[508].Nonce[1188]);
  pthread_cancel(runtime->p_scanhash);
  pthread_join(runtime->p_scanhash, 0);
  pthread_cancel(runtime->chain_status[runtime->chain_id].p_dispatch);
  pthread_join(runtime->chain_status[runtime->chain_id].p_dispatch, 0);
  uart_close(runtime->chain_status[runtime->chain_id].fd);
  reg_list_exit();
  work_list_exit();
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s Done!\n", "pcba_runtime_exit");
    applog(2, tmp42, 0);
  }
}
