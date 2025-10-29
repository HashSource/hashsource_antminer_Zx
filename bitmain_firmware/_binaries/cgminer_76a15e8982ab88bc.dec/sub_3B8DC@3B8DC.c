int __fastcall sub_3B8DC(int a1)
{
  int result; // r0

  switch ( a1 )
  {
    case 0:
      result = 1;
      break;
    case 1:
      result = 3;
      break;
    case 2:
      result = 5;
      break;
    case 6:
      result = 13;
      break;
    case 26:
      goto LABEL_3;
    default:
      printf("%s: Don't support ASIC baud = %d, error!!!\n", "asic_baud_to_fpga_baud", a1);
LABEL_3:
      result = 53;
      break;
  }
  return result;
}
