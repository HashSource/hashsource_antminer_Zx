void __cdecl bm174x_set_io_drive_strength(int fd, uint32_t value)
{
  base_type_t item; // [sp+8h] [bp+8h] BYREF

  item.chip_addr = 0;
  item.all = 1;
  item.addr = 48;
  item.data = value;
  reg_value.io_drive_strength = value;
  midd_ioctl(fd, 1u, &item);
}
