unsigned int __fastcall clear_uart_rx_fifo(unsigned __int8 which_chain)
{
  int v1; // r5
  pthread_mutex_t *v2; // r4
  size_t v3; // r0
  unsigned int v4; // r6
  unsigned __int8 *v5; // r0
  unsigned __int8 *v6; // r7
  unsigned int uart_data_in_fpga; // r3
  const char *v8; // r0

  v1 = which_chain;
  v2 = &uart_receive_mutex[which_chain];
  pthread_mutex_lock(v2);
  v3 = check_how_many_uart_data_in_fpga(v1);
  v4 = v3;
  if ( v3 )
  {
    v5 = (unsigned __int8 *)malloc(v3);
    v6 = v5;
    if ( !v5 )
    {
LABEL_5:
      usleep((__useconds_t)&nonce_fifo.nonce_buffer[20].chip_addr);
      pthread_mutex_unlock(v2);
      return 1;
    }
    uart_data_in_fpga = read_uart_data_in_fpga(v1, v5, v4);
    if ( v4 != uart_data_in_fpga )
    {
      LOWORD(v8) = -31196;
      HIWORD(v8) = (unsigned int)"--- %s\n" >> 16;
      printf(v8, "clear_uart_rx_fifo", v1, v4, uart_data_in_fpga);
      free(v6);
      goto LABEL_5;
    }
    v4 = 1;
    free(v6);
    usleep((__useconds_t)&nonce_fifo.nonce_buffer[20].chip_addr);
  }
  pthread_mutex_unlock(v2);
  return v4;
}
