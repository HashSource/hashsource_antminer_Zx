int __fastcall sub_3BB78(int a1)
{
  int result; // r0

  switch ( a1 )
  {
    case 0:
      result = HIWORD(*(_DWORD *)(dword_78E10[0] + 496)) & 0x3FF;
      break;
    case 1:
      result = *(_DWORD *)(dword_78E10[0] + 496) & 0x3FF;
      break;
    case 2:
      result = HIWORD(*(_DWORD *)(dword_78E10[0] + 500)) & 0x3FF;
      break;
    case 3:
      result = *(_DWORD *)(dword_78E10[0] + 500) & 0x3FF;
      break;
    case 4:
      result = HIWORD(*(_DWORD *)(dword_78E10[0] + 504)) & 0x3FF;
      break;
    case 5:
      result = *(_DWORD *)(dword_78E10[0] + 504) & 0x3FF;
      break;
    case 6:
      result = HIWORD(*(_DWORD *)(dword_78E10[0] + 508)) & 0x3FF;
      break;
    case 7:
      result = *(_DWORD *)(dword_78E10[0] + 508) & 0x3FF;
      break;
    case 8:
      result = HIWORD(*(_DWORD *)(dword_78E10[0] + 512)) & 0x3FF;
      break;
    case 9:
      result = *(_DWORD *)(dword_78E10[0] + 512) & 0x3FF;
      break;
    default:
      printf("%s: The uart%d is not supported!!!\n", "check_how_many_uart_data_in_fpga", a1);
      result = 0;
      break;
  }
  return result;
}
