int __cdecl bm174x_i2c_recv(int fd, uint8_t chip_addr, uint8_t i2c_dev_addr, uint8_t i2c_reg_addr, int len)
{
  base_type_t item; // [sp+8h] [bp+8h] BYREF
  bm174x_reg i2c_reg; // [sp+10h] [bp+10h]
  int i; // [sp+14h] [bp+14h]

  *(_BYTE *)&i2c_reg.chip_addr = reg_value.general_i2c_command;
  *((_BYTE *)&i2c_reg.pll_parameter + 3) = HIBYTE(reg_value.general_i2c_command) | 1;
  *((_BYTE *)&i2c_reg.hash_rate + 2) = 2 * (i2c_dev_addr & 0x7F);
  *((_BYTE *)&i2c_reg.chip_addr + 1) = i2c_reg_addr;
  item.chip_addr = chip_addr;
  item.all = 0;
  item.addr = 32;
  item.data = i2c_reg.core_timeout.core_timeout;
  midd_ioctl(fd, 1u, &item);
  usleep(0x30D40u);
  for ( i = 0; i < len; ++i )
  {
    item.all = 0;
    item.chip_addr = chip_addr;
    item.addr = 32;
    item.data = 0;
    midd_ioctl(fd, 0, &item);
    usleep((__useconds_t)&nonce_fifo.nonce_buffer[508].Nonce[1188]);
  }
  return 0;
}
