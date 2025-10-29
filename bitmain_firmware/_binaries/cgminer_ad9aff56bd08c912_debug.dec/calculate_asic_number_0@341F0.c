// Alternative name is 'calculate_asic_number.part.9'
int __fastcall calculate_asic_number_0(unsigned int actual_asic_number)
{
  const char *v1; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  LOWORD(v1) = -31944;
  HIWORD(v1) = (unsigned int)"er-btm-zcash.c" >> 16;
  snprintf(tmp42, 0x1000u, v1, actual_asic_number);
  applog(7, tmp42, 0);
  return -1;
}
