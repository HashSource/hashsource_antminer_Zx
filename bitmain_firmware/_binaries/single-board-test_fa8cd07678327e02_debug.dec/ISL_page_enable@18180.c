int __cdecl ISL_page_enable(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr, uint8_t which_page)
{
  uint8_t which_pagea; // [sp+Ch] [bp+4h] BYREF
  uint8_t i2c_dev_addra; // [sp+Dh] [bp+5h]
  uint8_t which_i2ca; // [sp+Eh] [bp+6h]
  uint8_t which_chaina[5]; // [sp+Fh] [bp+7h] BYREF

  which_chaina[0] = which_chain;
  which_i2ca = which_i2c;
  i2c_dev_addra = i2c_dev_addr;
  which_pagea = which_page;
  write_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0, &which_pagea, 1);
  return 0;
}
