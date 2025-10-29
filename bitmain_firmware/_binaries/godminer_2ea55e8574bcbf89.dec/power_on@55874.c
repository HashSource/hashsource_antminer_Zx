unsigned int power_on()
{
  bitmain_power_on();
  byte_174220 = 1;
  return sleep(1u);
}
