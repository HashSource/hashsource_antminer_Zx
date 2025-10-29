void green_led_on()
{
  write(green_led_fd, "1", 1u);
}
