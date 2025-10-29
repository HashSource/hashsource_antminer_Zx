unsigned int __cdecl clear_uart_rx_fifo(unsigned __int8 which_chain)
{
  char tmp42[1024]; // [sp+1Ch] [bp+Ch] BYREF
  unsigned __int8 *buf; // [sp+41Ch] [bp+40Ch]
  unsigned int nbytes; // [sp+420h] [bp+410h]
  unsigned int len; // [sp+424h] [bp+414h]

  len = 0;
  nbytes = 0;
  buf = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "clear_uart_rx_fifo");
    applog(2, tmp42, 0);
  }
  pthread_mutex_lock(&uart_receive_mutex[which_chain]);
  nbytes = check_how_many_uart_data_in_fpga(which_chain);
  if ( nbytes )
  {
    buf = (unsigned __int8 *)malloc(nbytes);
    if ( buf )
    {
      len = read_uart_data_in_fpga(which_chain, buf, nbytes);
      if ( len != nbytes && (use_syslog || opt_log_output || opt_log_level > 1) )
      {
        snprintf(
          tmp42,
          0x400u,
          "%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n",
          "clear_uart_rx_fifo",
          which_chain,
          nbytes,
          len);
        applog(2, tmp42, 0);
      }
      free(buf);
      buf = 0;
      usleep(0x2710u);
      pthread_mutex_unlock(&uart_receive_mutex[which_chain]);
      return 1;
    }
    else
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "%s: uart%d malloc buffer error\n", "clear_uart_rx_fifo", which_chain);
        applog(2, tmp42, 0);
      }
      buf = 0;
      usleep((__useconds_t)&nonce_fifo.nonce_buffer[140].Nonce[564]);
      pthread_mutex_unlock(&uart_receive_mutex[which_chain]);
      return 1;
    }
  }
  else
  {
    pthread_mutex_unlock(&uart_receive_mutex[which_chain]);
    return 0;
  }
}
