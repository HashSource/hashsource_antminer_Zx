unsigned int __cdecl check_how_many_uart_data_in_fpga(unsigned __int8 which_uart)
{
  unsigned int v1; // r3
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF

  switch ( which_uart )
  {
    case 0u:
      v1 = (read_axi_fpga(0x440u) >> 16) & 0x3FF;
      break;
    case 1u:
      v1 = read_axi_fpga(0x440u) & 0x3FF;
      break;
    case 2u:
      v1 = (read_axi_fpga(0x441u) >> 16) & 0x3FF;
      break;
    case 3u:
      v1 = read_axi_fpga(0x441u) & 0x3FF;
      break;
    case 4u:
      v1 = (read_axi_fpga(0x442u) >> 16) & 0x3FF;
      break;
    case 5u:
      v1 = read_axi_fpga(0x442u) & 0x3FF;
      break;
    case 6u:
      v1 = (read_axi_fpga(0x443u) >> 16) & 0x3FF;
      break;
    case 7u:
      v1 = read_axi_fpga(0x443u) & 0x3FF;
      break;
    case 8u:
      v1 = (read_axi_fpga(0x444u) >> 16) & 0x3FF;
      break;
    case 9u:
      v1 = read_axi_fpga(0x444u) & 0x3FF;
      break;
    default:
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "%s: The uart%d is not supported!!!\n", "check_how_many_uart_data_in_fpga", which_uart);
        applog(2, tmp42, 0);
      }
      v1 = 0;
      break;
  }
  return v1;
}
