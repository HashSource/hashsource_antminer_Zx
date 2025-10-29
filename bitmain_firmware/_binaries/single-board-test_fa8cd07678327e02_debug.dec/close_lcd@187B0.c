int close_lcd()
{
  char tmp42[1024]; // [sp+4h] [bp+4h] BYREF
  int ret; // [sp+404h] [bp+404h]

  ret = close(cgpu.lcd_fd);
  if ( ret )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "lcd close failed!!!\n");
      applog(2, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "lcd closed!!!\n");
    applog(2, tmp42, 0);
  }
  return ret;
}
