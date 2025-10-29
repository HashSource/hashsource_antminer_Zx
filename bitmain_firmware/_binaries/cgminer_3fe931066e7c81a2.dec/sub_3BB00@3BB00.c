int __fastcall sub_3BB00(int result)
{
  if ( result != 1 )
  {
    if ( result )
    {
      if ( result != 26 )
      {
        printf("%s: Don't support ASIC baud = %d, error!!!\n", "asic_baud_to_fpga_baud", result);
        return 53;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
