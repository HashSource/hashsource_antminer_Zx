unsigned int __cdecl uart_receive(unsigned __int8 which_uart, unsigned __int8 *buf, unsigned int buf_length)
{
  unsigned int nbytes; // [sp+10h] [bp+10h]
  unsigned int len; // [sp+14h] [bp+14h]

  pthread_mutex_lock(&uart_receive_mutex[which_uart]);
  nbytes = check_how_many_uart_data_in_fpga(which_uart);
  if ( nbytes < buf_length )
  {
    if ( nbytes )
      len = read_uart_data_in_fpga(which_uart, buf, nbytes);
    else
      len = 0;
  }
  else
  {
    len = read_uart_data_in_fpga(which_uart, buf, buf_length);
  }
  pthread_mutex_unlock(&uart_receive_mutex[which_uart]);
  return len;
}
