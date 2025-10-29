int __fastcall ZCASH_read(int uart_fd, unsigned __int8 *buf, size_t MAX_READ_BYTES)
{
  return uart_receive(uart_fd, buf, MAX_READ_BYTES);
}
