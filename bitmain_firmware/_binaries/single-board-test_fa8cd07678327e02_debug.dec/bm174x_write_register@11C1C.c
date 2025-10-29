void __cdecl bm174x_write_register(int fd, int mode, uint8_t chip_addr, uint8_t reg_addr, uint32_t reg_data)
{
  base_type_t item; // [sp+10h] [bp+10h] BYREF

  item.all = mode;
  item.chip_addr = chip_addr;
  item.addr = reg_addr;
  item.data = reg_data;
  midd_ioctl(fd, 1u, &item);
}
