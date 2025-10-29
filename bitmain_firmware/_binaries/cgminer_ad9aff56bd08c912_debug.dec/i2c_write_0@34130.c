// Alternative name is 'i2c_write.part.1'
void __fastcall i2c_write_0(unsigned int config_data)
{
  const char *v1; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  LOWORD(v1) = -31972;
  HIWORD(v1) = (unsigned int)"rt > /dev/null 2>&1 &" >> 16;
  snprintf(tmp42, 0x1000u, v1, "i2c_write");
  applog(5, tmp42, 0);
}
