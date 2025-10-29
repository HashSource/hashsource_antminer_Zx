void __cdecl bm174x_i2c_status(int fd, uint8_t chip_addr)
{
  base_type_t item; // [sp+8h] [bp+8h] BYREF

  item.data = 0;
  *(_DWORD *)&item.chip_addr = chip_addr;
  item.addr = 32;
  midd_ioctl(fd, 0, &item);
}
