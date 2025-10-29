void red_led_on()
{
  write(red_led_fd, "1", 1u);
}
