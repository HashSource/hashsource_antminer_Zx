int bitmain_power_on()
{
  if ( !is_gpio_exist(dword_171CC0) )
  {
    gpio_export(dword_171CC0);
    gpio_direction(dword_171CC0, 1);
  }
  return gpio_write(dword_171CC0, 0);
}
