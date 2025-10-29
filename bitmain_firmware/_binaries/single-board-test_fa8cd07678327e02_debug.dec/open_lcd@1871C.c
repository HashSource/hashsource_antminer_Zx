int open_lcd()
{
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF

  cgpu.lcd_fd = open("/dev/bitmain-lcd", 2178);
  if ( cgpu.lcd_fd <= 0 && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    strcpy(tmp42, "open lcd failed!!!\n");
    applog(2, tmp42, 0);
  }
  return cgpu.lcd_fd;
}
