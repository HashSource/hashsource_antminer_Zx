int __fastcall ISL_get_voltage(uint8_t i2c_dev_addr, uint16_t *voltage)
{
  uint8_t vol[8]; // [sp+4h] [bp-8h] BYREF

  *(_WORD *)vol = 0;
  read_dc_dc(i2c_dev_addr, 0x21u, vol, 2);
  *voltage = vol[0] | (vol[1] << 8);
  return 0;
}
