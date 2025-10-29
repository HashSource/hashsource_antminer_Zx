unsigned int __cdecl read_uart_data_in_fpga(unsigned __int8 which_uart, unsigned __int8 *buf, unsigned int length)
{
  unsigned int v3; // r3
  char tmp42[1024]; // [sp+1Ch] [bp+14h] BYREF
  unsigned int ret_data; // [sp+41Ch] [bp+414h]
  unsigned int read_loop; // [sp+420h] [bp+418h]
  unsigned int data; // [sp+424h] [bp+41Ch]
  unsigned int ret_length; // [sp+428h] [bp+420h]
  unsigned int i; // [sp+42Ch] [bp+424h]
  unsigned int chain_read_data_addr; // [sp+430h] [bp+428h]
  unsigned int chain_read_enable_addr; // [sp+434h] [bp+42Ch]

  chain_read_enable_addr = 0;
  chain_read_data_addr = 0;
  data = 0;
  read_loop = 0;
  i = 0;
  ret_data = 0;
  ret_length = 0;
  switch ( which_uart )
  {
    case 0u:
      chain_read_enable_addr = 1100;
      chain_read_data_addr = 1101;
      goto LABEL_17;
    case 1u:
      chain_read_enable_addr = 1102;
      chain_read_data_addr = 1103;
      goto LABEL_17;
    case 2u:
      chain_read_enable_addr = 1104;
      chain_read_data_addr = 1105;
      goto LABEL_17;
    case 3u:
      chain_read_enable_addr = 1106;
      chain_read_data_addr = 1107;
      goto LABEL_17;
    case 4u:
      chain_read_enable_addr = 1108;
      chain_read_data_addr = 1109;
      goto LABEL_17;
    case 5u:
      chain_read_enable_addr = 1110;
      chain_read_data_addr = 1111;
      goto LABEL_17;
    case 6u:
      chain_read_enable_addr = 1112;
      chain_read_data_addr = 1113;
      goto LABEL_17;
    case 7u:
      chain_read_enable_addr = 1114;
      chain_read_data_addr = 1115;
      goto LABEL_17;
    case 8u:
      chain_read_enable_addr = 1116;
      chain_read_data_addr = 1117;
      goto LABEL_17;
    case 9u:
      chain_read_enable_addr = 1118;
      chain_read_data_addr = 1119;
LABEL_17:
      data = length & 0x3FF | 0x80000000;
      write_axi_fpga(chain_read_enable_addr, data);
      read_loop = length >> 2;
      for ( i = 0; i < read_loop; ++i )
      {
        ret_data = read_axi_fpga(chain_read_data_addr);
        buf[4 * i] = HIBYTE(ret_data);
        buf[4 * i + 1] = BYTE2(ret_data);
        buf[4 * i + 2] = BYTE1(ret_data);
        buf[4 * i + 3] = ret_data;
      }
      ret_length = 4 * read_loop;
      read_loop = length & 3;
      if ( (length & 3) != 0 )
      {
        ret_data = read_axi_fpga(chain_read_data_addr);
        switch ( read_loop )
        {
          case 2u:
            buf[4 * i] = HIBYTE(ret_data);
            buf[4 * i + 1] = BYTE2(ret_data);
            ret_length += 2;
            break;
          case 3u:
            buf[4 * i] = HIBYTE(ret_data);
            buf[4 * i + 1] = BYTE2(ret_data);
            buf[4 * i + 2] = BYTE1(ret_data);
            ret_length += 3;
            break;
          case 1u:
            buf[4 * i] = HIBYTE(ret_data);
            ++ret_length;
            break;
          default:
            if ( use_syslog || opt_log_output || opt_log_level > 1 )
            {
              snprintf(
                tmp42,
                0x400u,
                "%s: the uart%d left data is 4*N length, error!!!\n",
                "read_uart_data_in_fpga",
                which_uart);
              applog(2, tmp42, 0);
            }
            break;
        }
      }
      v3 = ret_length;
      break;
    default:
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "%s: The uart%d is not supported!!!\n", "read_uart_data_in_fpga", which_uart);
        applog(2, tmp42, 0);
      }
      v3 = 0;
      break;
  }
  return v3;
}
