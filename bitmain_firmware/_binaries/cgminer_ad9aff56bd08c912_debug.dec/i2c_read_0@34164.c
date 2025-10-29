// Alternative name is 'i2c_read.part.2'
int __fastcall i2c_read_0(unsigned int config_data)
{
  const char *v1; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  LOWORD(v1) = -31972;
  HIWORD(v1) = (unsigned int)"rt > /dev/null 2>&1 &" >> 16;
  snprintf(tmp42, 0x1000u, v1, "i2c_read");
  applog(5, tmp42, 0);
  return 255;
}
