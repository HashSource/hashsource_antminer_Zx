int __fastcall sub_3B9B4(int a1)
{
  int result; // r0

  switch ( a1 )
  {
    case 0:
      result = HIWORD(*(_DWORD *)(dword_75C50[0] + 4352)) & 0x3FF;
      break;
    case 1:
      result = *(_DWORD *)(dword_75C50[0] + 4352) & 0x3FF;
      break;
    case 2:
      result = HIWORD(*(_DWORD *)(dword_75C50[0] + 4356)) & 0x3FF;
      break;
    case 3:
      result = *(_DWORD *)(dword_75C50[0] + 4356) & 0x3FF;
      break;
    case 4:
      result = HIWORD(*(_DWORD *)(dword_75C50[0] + 4360)) & 0x3FF;
      break;
    case 5:
      result = *(_DWORD *)(dword_75C50[0] + 4360) & 0x3FF;
      break;
    case 6:
      result = HIWORD(*(_DWORD *)(dword_75C50[0] + 4364)) & 0x3FF;
      break;
    case 7:
      result = *(_DWORD *)(dword_75C50[0] + 4364) & 0x3FF;
      break;
    case 8:
      result = HIWORD(*(_DWORD *)(dword_75C50[0] + 4368)) & 0x3FF;
      break;
    case 9:
      result = *(_DWORD *)(dword_75C50[0] + 4368) & 0x3FF;
      break;
    default:
      printf("%s: The uart%d is not supported!!!\n", "check_how_many_uart_data_in_fpga", a1);
      result = 0;
      break;
  }
  return result;
}
