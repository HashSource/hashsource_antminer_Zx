int open_key()
{
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF

  cgpu.key_fd = open("/sys/class/gpio/gpio943/value", 2048);
  if ( cgpu.key_fd < 0 && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    strcpy(tmp42, "open key failed!!!\n");
    applog(2, tmp42, 0);
  }
  return cgpu.key_fd;
}
