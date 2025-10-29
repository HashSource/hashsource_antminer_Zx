unsigned int __fastcall uart_receive(unsigned __int8 which_uart, unsigned __int8 *buf, unsigned int buf_length)
{
  pthread_mutex_t *v6; // r4
  unsigned int v7; // r0
  unsigned int v9; // r6
  unsigned int uart_data_in_fpga; // r6

  v6 = &uart_receive_mutex[which_uart];
  pthread_mutex_lock(v6);
  v7 = check_how_many_uart_data_in_fpga(which_uart);
  if ( v7 >= buf_length )
  {
    uart_data_in_fpga = read_uart_data_in_fpga(which_uart, buf, buf_length);
    pthread_mutex_unlock(v6);
    return uart_data_in_fpga;
  }
  else if ( v7 )
  {
    v9 = read_uart_data_in_fpga(which_uart, buf, v7);
    pthread_mutex_unlock(v6);
    return v9;
  }
  else
  {
    pthread_mutex_unlock(v6);
    return 0;
  }
}
