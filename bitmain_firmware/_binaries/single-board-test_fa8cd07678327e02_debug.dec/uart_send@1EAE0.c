unsigned int __cdecl uart_send(unsigned __int8 which_uart, unsigned __int8 *buf, unsigned int length)
{
  unsigned int axi_fpga; // r0
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  unsigned __int8 send_buf[512]; // [sp+418h] [bp+410h] BYREF
  unsigned int max_fpga_can_send_uart_data_len; // [sp+618h] [bp+610h]
  unsigned int send_data_len; // [sp+61Ch] [bp+614h]
  int send_loop; // [sp+620h] [bp+618h]
  unsigned int bit_shift_num; // [sp+624h] [bp+61Ch]
  unsigned int chain_send_buffer_addr; // [sp+628h] [bp+620h]
  unsigned int chain_send_ready_addr; // [sp+62Ch] [bp+624h]
  unsigned int chain_send_fifo_status_addr; // [sp+630h] [bp+628h]
  unsigned int send_data; // [sp+634h] [bp+62Ch]
  int i; // [sp+638h] [bp+630h]
  int send_counter; // [sp+63Ch] [bp+634h]

  send_counter = 0;
  send_loop = 0;
  i = 0;
  memset(send_buf, 0, sizeof(send_buf));
  send_data_len = length;
  send_data = 0;
  chain_send_fifo_status_addr = 0;
  chain_send_ready_addr = 0;
  chain_send_buffer_addr = 0;
  max_fpga_can_send_uart_data_len = 0;
  bit_shift_num = 0;
  pthread_mutex_lock(&uart_send_mutex[which_uart]);
  switch ( which_uart )
  {
    case 0u:
      bit_shift_num = 24;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1028;
      chain_send_buffer_addr = 1029;
      goto LABEL_17;
    case 1u:
      bit_shift_num = 16;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1030;
      chain_send_buffer_addr = 1031;
      goto LABEL_17;
    case 2u:
      bit_shift_num = 8;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1032;
      chain_send_buffer_addr = 1033;
      goto LABEL_17;
    case 3u:
      bit_shift_num = 0;
      chain_send_fifo_status_addr = 1024;
      chain_send_ready_addr = 1034;
      chain_send_buffer_addr = 1035;
      goto LABEL_17;
    case 4u:
      bit_shift_num = 24;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1036;
      chain_send_buffer_addr = 1037;
      goto LABEL_17;
    case 5u:
      bit_shift_num = 16;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1038;
      chain_send_buffer_addr = 1039;
      goto LABEL_17;
    case 6u:
      bit_shift_num = 8;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1040;
      chain_send_buffer_addr = 1041;
      goto LABEL_17;
    case 7u:
      bit_shift_num = 0;
      chain_send_fifo_status_addr = 1025;
      chain_send_ready_addr = 1042;
      chain_send_buffer_addr = 1043;
      goto LABEL_17;
    case 8u:
      bit_shift_num = 24;
      chain_send_fifo_status_addr = 1026;
      chain_send_ready_addr = 1044;
      chain_send_buffer_addr = 1045;
      goto LABEL_17;
    case 9u:
      bit_shift_num = 16;
      chain_send_fifo_status_addr = 1026;
      chain_send_ready_addr = 1046;
      chain_send_buffer_addr = 1047;
LABEL_17:
      send_counter = 0;
      break;
    default:
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "%s: The uart%d is not supported!!!\n", "uart_send", which_uart);
        applog(2, tmp42, 0);
      }
      return 0;
  }
  while ( 1 )
  {
    axi_fpga = read_axi_fpga(chain_send_fifo_status_addr);
    max_fpga_can_send_uart_data_len = (unsigned __int8)(axi_fpga >> bit_shift_num);
    if ( max_fpga_can_send_uart_data_len >= length )
      break;
    usleep(0xBB8u);
    if ( ++send_counter > 20 )
    {
      pthread_mutex_unlock(&uart_send_mutex[which_uart]);
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(
          tmp42,
          0x400u,
          "%s: uart%d always dose not has enough send fifo space, break\n",
          "uart_send",
          which_uart);
        applog(2, tmp42, 0);
      }
      return 0;
    }
  }
  send_counter = 0;
  while ( 1 )
  {
    if ( (read_axi_fpga(chain_send_ready_addr) & 0x80000000) == 0 )
    {
      memcpy(send_buf, buf, length);
      send_loop = send_data_len >> 2;
      for ( i = 0; i < send_loop; ++i )
      {
        send_data = (send_buf[4 * i + 2] << 8)
                  | (send_buf[4 * i] << 24)
                  | (send_buf[4 * i + 1] << 16)
                  | send_buf[4 * i + 3];
        write_axi_fpga(chain_send_buffer_addr, send_data);
      }
      send_loop = send_data_len & 3;
      if ( (send_data_len & 3) != 0 )
      {
        switch ( send_loop )
        {
          case 2:
            send_data = (send_buf[4 * i + 1] << 16) | (send_buf[4 * i] << 24);
            break;
          case 3:
            send_data = (send_buf[4 * i + 2] << 8) | (send_buf[4 * i] << 24) | (send_buf[4 * i + 1] << 16);
            break;
          case 1:
            send_data = send_buf[4 * i] << 24;
            break;
          default:
            if ( use_syslog || opt_log_output || opt_log_level > 1 )
            {
              snprintf(
                tmp42,
                0x400u,
                "%s: the uart%d send left data is 4*N length, error!!!\n",
                "uart_send",
                which_uart);
              applog(2, tmp42, 0);
            }
            break;
        }
        write_axi_fpga(chain_send_buffer_addr, send_data);
      }
      write_axi_fpga(chain_send_ready_addr, send_data_len | 0x80000000);
      pthread_mutex_unlock(&uart_send_mutex[which_uart]);
      return send_data_len;
    }
    if ( send_counter > 20 )
      break;
    ++send_counter;
    usleep(0xBB8u);
  }
  pthread_mutex_unlock(&uart_send_mutex[which_uart]);
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s: uart%d always busy, break\n", "uart_send", which_uart);
    applog(2, tmp42, 0);
  }
  return 0;
}
