unsigned int __fastcall check_how_many_uart_data_in_fpga(unsigned __int8 which_uart)
{
  unsigned int result; // r0

  switch ( which_uart )
  {
    case 0u:
      result = HIWORD(axi_fpga_addr[124]) & 0x3FF;
      break;
    case 1u:
      result = axi_fpga_addr[124] & 0x3FF;
      break;
    case 2u:
      result = HIWORD(axi_fpga_addr[125]) & 0x3FF;
      break;
    case 3u:
      result = axi_fpga_addr[125] & 0x3FF;
      break;
    case 4u:
      result = HIWORD(axi_fpga_addr[126]) & 0x3FF;
      break;
    case 5u:
      result = axi_fpga_addr[126] & 0x3FF;
      break;
    case 6u:
      result = HIWORD(axi_fpga_addr[127]) & 0x3FF;
      break;
    case 7u:
      result = axi_fpga_addr[127] & 0x3FF;
      break;
    case 8u:
      result = HIWORD(axi_fpga_addr[128]) & 0x3FF;
      break;
    case 9u:
      result = axi_fpga_addr[128] & 0x3FF;
      break;
    default:
      printf("%s: The uart%d is not supported!!!\n", "check_how_many_uart_data_in_fpga", which_uart);
      result = 0;
      break;
  }
  return result;
}
