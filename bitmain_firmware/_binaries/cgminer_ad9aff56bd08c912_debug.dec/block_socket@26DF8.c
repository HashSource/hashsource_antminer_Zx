void __fastcall block_socket(int fd)
{
  unsigned int v2; // r2

  v2 = fcntl(fd, 3, 0) & 0xFFFFF7FF;
  j_fcntl(fd, 4, v2);
}
