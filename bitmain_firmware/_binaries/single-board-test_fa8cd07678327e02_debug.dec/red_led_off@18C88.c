void red_led_off()
{
  write(red_led_fd, "0", 1u);
}
