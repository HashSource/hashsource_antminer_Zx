int __cdecl ISL_get_voltage(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr, uint16_t *voltage)
{
  uint8_t which_chaina[5]; // [sp+Fh] [bp+7h] BYREF
  uint8_t vol[4]; // [sp+14h] [bp+Ch] BYREF

  which_chaina[0] = which_chain;
  memset(vol, 0, 2u);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0x21u, vol, 2);
  *voltage = (vol[1] << 8) | vol[0];
  return 0;
}
