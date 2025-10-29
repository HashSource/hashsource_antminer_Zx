unsigned int __cdecl clear_uart_send_fifo(unsigned __int8 which_chain)
{
  unsigned int axi_fpga; // r0
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF
  unsigned int max_fpga_can_send_uart_data_len; // [sp+410h] [bp+408h]
  unsigned int chain_send_buffer_addr; // [sp+414h] [bp+40Ch]
  unsigned int send_counter; // [sp+418h] [bp+410h]
  unsigned int bit_shift_num; // [sp+41Ch] [bp+414h]
  unsigned int chain_send_ready_addr; // [sp+420h] [bp+418h]
  unsigned int chain_send_fifo_status_addr; // [sp+424h] [bp+41Ch]

  chain_send_fifo_status_addr = 0;
  chain_send_ready_addr = 0;
  max_fpga_can_send_uart_data_len = 0;
  bit_shift_num = 0;
  send_counter = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "clear_uart_send_fifo");
    applog(2, tmp42, 0);
  }
  pthread_mutex_lock(&uart_send_mutex[which_chain]);
  switch ( which_chain )
  {
    case 0u:
      bit_shift_num = 24;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1028;
      chain_send_buffer_addr = 1029;
      goto LABEL_21;
    case 1u:
      bit_shift_num = 16;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1030;
      chain_send_buffer_addr = 1031;
      goto LABEL_21;
    case 2u:
      bit_shift_num = 8;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1032;
      chain_send_buffer_addr = 1033;
      goto LABEL_21;
    case 3u:
      bit_shift_num = 0;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1034;
      chain_send_buffer_addr = 1035;
      goto LABEL_21;
    case 4u:
      bit_shift_num = 24;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1036;
      chain_send_buffer_addr = 1037;
      goto LABEL_21;
    case 5u:
      bit_shift_num = 16;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1038;
      chain_send_buffer_addr = 1039;
      goto LABEL_21;
    case 6u:
      bit_shift_num = 8;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1040;
      chain_send_buffer_addr = 1041;
      goto LABEL_21;
    case 7u:
      bit_shift_num = 0;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1042;
      chain_send_buffer_addr = 1043;
      goto LABEL_21;
    case 8u:
      bit_shift_num = 24;
      chain_send_fifo_status_addr = 1026;
      chain_send_ready_addr = 1044;
      chain_send_buffer_addr = 1045;
      goto LABEL_21;
    case 9u:
      bit_shift_num = 16;
      chain_send_fifo_status_addr = 1026;
      chain_send_ready_addr = 1046;
      chain_send_buffer_addr = 1047;
LABEL_21:
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 3) )
      {
        snprintf(
          tmp42,
          0x400u,
          "chain_send_ready_addr: 0x%08x, chain_send_buffer_addr: 0x%08x",
          chain_send_ready_addr,
          chain_send_buffer_addr);
        applog(4, tmp42, 0);
      }
      send_counter = 0;
      break;
    default:
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "%s: The uart%d is not supported!!!\n", "clear_uart_send_fifo", which_chain);
        applog(2, tmp42, 0);
      }
      pthread_mutex_unlock(&uart_send_mutex[which_chain]);
      return 1;
  }
  do
  {
    axi_fpga = read_axi_fpga(chain_send_fifo_status_addr);
    max_fpga_can_send_uart_data_len = (unsigned __int8)(axi_fpga >> bit_shift_num);
    if ( max_fpga_can_send_uart_data_len == 255 )
    {
      pthread_mutex_unlock(&uart_send_mutex[which_chain]);
      return 0;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(
        tmp42,
        0x400u,
        "%s: waiting fpga uart%d clear send fifo space ...\n",
        "clear_uart_send_fifo",
        which_chain);
      applog(2, tmp42, 0);
    }
    usleep(0xBB8u);
    ++send_counter;
  }
  while ( send_counter <= 0x14 );
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "%s: uart%d always dose not has enough send fifo space, break\n",
      "clear_uart_send_fifo",
      which_chain);
    applog(2, tmp42, 0);
  }
  pthread_mutex_unlock(&uart_send_mutex[which_chain]);
  return max_fpga_can_send_uart_data_len;
}
