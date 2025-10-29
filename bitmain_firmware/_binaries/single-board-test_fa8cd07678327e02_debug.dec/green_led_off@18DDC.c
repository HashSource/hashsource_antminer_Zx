void green_led_off()
{
  write(green_led_fd, "0", 1u);
}
