void __cdecl bm174x_i2c_enable(int fd, uint8_t chip_addr)
{
  base_type_t item; // [sp+Ch] [bp+Ch] BYREF
  bm174x_reg misc_reg; // [sp+14h] [bp+14h]

  misc_reg.core_timeout.core_timeout = reg_value.misc_control | 0x4060;
  item.chip_addr = chip_addr;
  item.all = 0;
  item.addr = 28;
  item.data = reg_value.misc_control | 0x4060;
  midd_ioctl(fd, 1u, &item);
}
