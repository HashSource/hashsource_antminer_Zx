int __cdecl ISL_set_vout_command(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr, uint16_t voltage)
{
  uint8_t which_chaina[5]; // [sp+Fh] [bp+7h] BYREF
  uint8_t cmd[8]; // [sp+14h] [bp+Ch] BYREF

  which_chaina[0] = which_chain;
  *(_WORD *)cmd = voltage;
  printf("uint16 = 0x%04x[%u], cmd0=%02x cmd1=%02x\n", voltage, voltage, (unsigned __int8)voltage, HIBYTE(voltage));
  write_dc_dc(which_chaina, which_i2c, i2c_dev_addr, 0x21u, cmd, 2);
  return 0;
}
