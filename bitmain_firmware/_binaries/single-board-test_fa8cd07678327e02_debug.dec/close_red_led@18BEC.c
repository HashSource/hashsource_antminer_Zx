void close_red_led()
{
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF

  close(red_led_fd);
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "red led closed!!!\n");
    applog(2, tmp42, 0);
  }
}
