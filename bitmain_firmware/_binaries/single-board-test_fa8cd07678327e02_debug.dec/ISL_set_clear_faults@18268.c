int __cdecl ISL_set_clear_faults(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr)
{
  uint8_t which_chaina[8]; // [sp+Fh] [bp+7h] BYREF
  uint8_t clear; // [sp+17h] [bp+Fh] BYREF

  which_chaina[0] = which_chain;
  clear = 1;
  write_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 3u, &clear, 1);
  return 0;
}
