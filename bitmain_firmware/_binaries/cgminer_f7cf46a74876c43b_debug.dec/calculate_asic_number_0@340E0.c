// Alternative name is 'calculate_asic_number.part.9'
int __fastcall calculate_asic_number_0(unsigned int actual_asic_number)
{
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  snprintf(tmp42, 0x1000u, "actual_asic_number = %d, but it is error\n", actual_asic_number);
  applog(7, tmp42, 0);
  return -1;
}
