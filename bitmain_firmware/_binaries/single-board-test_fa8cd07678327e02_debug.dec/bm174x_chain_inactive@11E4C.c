void __cdecl bm174x_chain_inactive(int fd)
{
  midd_ioctl(fd, 4u, 0);
}
