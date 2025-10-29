void fan_power_on()
{
  system("echo 1 > /sys/class/gpio/gpio954/value");
  j_system("echo 1 > /sys/class/gpio/gpio955/value");
}
