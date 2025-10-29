int __cdecl v9_key_read(char *command, int len)
{
  lseek(cgpu.key_fd, 0, 0);
  return read(cgpu.key_fd, command, len);
}
