void __cdecl bm174x_set_address(int fd, uint8_t address)
{
  uint8_t addressa; // [sp+3h] [bp+3h] BYREF
  int fda; // [sp+4h] [bp+4h]

  fda = fd;
  addressa = address;
  midd_ioctl(fd, 3u, &addressa);
}
