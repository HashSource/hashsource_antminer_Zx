void __cdecl bm174x_send_work(int fd, uint8_t *buf)
{
  midd_ioctl(fd, 2u, buf);
}
