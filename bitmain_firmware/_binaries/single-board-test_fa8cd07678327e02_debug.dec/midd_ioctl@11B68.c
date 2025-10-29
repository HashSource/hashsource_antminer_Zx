int __cdecl midd_ioctl(int fd, uint32_t oper_type, void *param)
{
  unsigned __int8 fda; // [sp+Ch] [bp+Ch]
  uint8_t str[300]; // [sp+10h] [bp+10h] BYREF
  int len; // [sp+13Ch] [bp+13Ch]

  fda = fd;
  memset(str, 0, sizeof(str));
  len = pack_ioctl_pkg(str, 0x12Cu, oper_type, param);
  if ( len >= 0 )
    return uart_send(fda, str, len);
  else
    return len;
}
