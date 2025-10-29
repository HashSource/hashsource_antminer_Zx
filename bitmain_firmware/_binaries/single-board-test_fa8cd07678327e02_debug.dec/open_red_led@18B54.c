int open_red_led()
{
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF

  red_led_fd = open("/sys/class/gpio/gpio941/value", 2049);
  if ( red_led_fd < 0 && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    strcpy(tmp42, "open red led failed!!!\n");
    applog(2, tmp42, 0);
  }
  return red_led_fd;
}
