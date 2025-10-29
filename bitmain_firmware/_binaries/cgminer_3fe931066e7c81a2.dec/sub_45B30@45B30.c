int sub_45B30()
{
  system("echo 1 > /sys/class/gpio/gpio954/value");
  return system("echo 1 > /sys/class/gpio/gpio955/value");
}
