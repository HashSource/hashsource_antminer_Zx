void __cdecl bm174x_i2c_send(
        int fd,
        uint8_t chip_addr,
        uint8_t i2c_dev_addr,
        uint8_t i2c_reg_addr,
        uint8_t *reg_data,
        int len)
{
  base_type_t item; // [sp+8h] [bp+8h] BYREF
  bm174x_reg i2c_reg; // [sp+10h] [bp+10h]
  int i; // [sp+14h] [bp+14h]

  for ( i = 0; i < len; ++i )
  {
    *(_BYTE *)&i2c_reg.chip_addr = reg_value.general_i2c_command;
    *((_BYTE *)&i2c_reg.pll_parameter + 3) = HIBYTE(reg_value.general_i2c_command) | 1;
    *((_BYTE *)&i2c_reg.hash_rate + 2) = (2 * (i2c_dev_addr & 0x7F)) | 1;
    *((_BYTE *)&i2c_reg.chip_addr + 1) = i2c_reg_addr;
    *(_BYTE *)&i2c_reg.chip_addr = reg_data[i];
    item.chip_addr = chip_addr;
    item.all = 0;
    item.addr = 32;
    item.data = i2c_reg.core_timeout.core_timeout;
    midd_ioctl(fd, 1u, &item);
  }
}
