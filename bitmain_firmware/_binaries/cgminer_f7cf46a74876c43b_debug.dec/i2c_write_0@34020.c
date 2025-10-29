// Alternative name is 'i2c_write.part.1'
void __fastcall i2c_write_0(unsigned int config_data)
{
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  snprintf(tmp42, 0x1000u, "%s: i2c always busy, break\n", "i2c_write");
  applog(5, tmp42, 0);
}
