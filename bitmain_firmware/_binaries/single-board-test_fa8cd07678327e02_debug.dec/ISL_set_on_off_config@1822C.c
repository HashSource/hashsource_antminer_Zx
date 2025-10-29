int __cdecl ISL_set_on_off_config(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr, uint8_t config)
{
  uint8_t configa; // [sp+Ch] [bp+4h] BYREF
  uint8_t i2c_dev_addra; // [sp+Dh] [bp+5h]
  uint8_t which_i2ca; // [sp+Eh] [bp+6h]
  uint8_t which_chaina[5]; // [sp+Fh] [bp+7h] BYREF

  which_chaina[0] = which_chain;
  which_i2ca = which_i2c;
  i2c_dev_addra = i2c_dev_addr;
  configa = config;
  write_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 2u, &configa, 1);
  return 0;
}
