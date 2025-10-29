int __cdecl uart_close(int fd)
{
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s fd=%d\n", "uart_exit", fd);
    applog(2, tmp42, 0);
  }
  return 0;
}
