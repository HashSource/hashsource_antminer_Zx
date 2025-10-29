int open_green_led()
{
  char tmp42[1024]; // [sp+0h] [bp+0h] BYREF

  green_led_fd = open("/sys/class/gpio/gpio942/value", 2049);
  if ( green_led_fd < 0 && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    strcpy(tmp42, "open green led failed!!!\n");
    applog(2, tmp42, 0);
  }
  return green_led_fd;
}
