void __cdecl bm174x_read_register(int fd, int mode, uint8_t chip_addr, uint8_t reg_addr)
{
  base_type_t item; // [sp+10h] [bp+10h] BYREF

  item.all = mode;
  item.chip_addr = chip_addr;
  item.addr = reg_addr;
  item.data = 0;
  midd_ioctl(fd, 0, &item);
}
