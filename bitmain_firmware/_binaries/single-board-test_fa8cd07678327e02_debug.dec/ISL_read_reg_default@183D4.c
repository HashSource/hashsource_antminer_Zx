int __cdecl ISL_read_reg_default(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr)
{
  uint8_t which_chaina[5]; // [sp+Fh] [bp+7h] BYREF
  uint8_t value[4]; // [sp+14h] [bp+Ch] BYREF

  which_chaina[0] = which_chain;
  value[0] = 0;
  value[1] = 0;
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0, value, 1);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 1u, value, 1);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 2u, value, 1);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 3u, value, 1);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0x10u, value, 1);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0x21u, value, 2);
  read_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0x22u, value, 1);
  return 0;
}
