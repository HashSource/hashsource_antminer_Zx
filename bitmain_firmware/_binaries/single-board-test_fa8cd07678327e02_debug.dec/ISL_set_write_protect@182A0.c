int __cdecl ISL_set_write_protect(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr, uint8_t mode)
{
  uint8_t modea; // [sp+Ch] [bp+4h] BYREF
  uint8_t i2c_dev_addra; // [sp+Dh] [bp+5h]
  uint8_t which_i2ca; // [sp+Eh] [bp+6h]
  uint8_t which_chaina[5]; // [sp+Fh] [bp+7h] BYREF

  which_chaina[0] = which_chain;
  which_i2ca = which_i2c;
  i2c_dev_addra = i2c_dev_addr;
  modea = mode;
  write_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0x10u, &modea, 1);
  return 0;
}
