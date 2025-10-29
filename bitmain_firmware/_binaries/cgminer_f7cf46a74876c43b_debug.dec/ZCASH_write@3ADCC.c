int __fastcall ZCASH_write(int fd, volatile uint8_t *buf, size_t bufLen)
{
  return uart_send(fd, buf, bufLen);
}
