void __fastcall set_led(bool stop)
{
  char cmd[100]; // [sp+4h] [bp-64h] BYREF

  blink_15605 ^= 1u;
  if ( stop )
  {
    sprintf(cmd, "echo %d > /sys/class/gpio/gpio%d/value", 0, 942);
    system(cmd);
    sprintf(cmd, "echo %d > /sys/class/gpio/gpio%d/value", (unsigned __int8)blink_15605, 941);
  }
  else
  {
    sprintf(cmd, "echo %d > /sys/class/gpio/gpio%d/value", 0, 941);
    system(cmd);
    sprintf(cmd, "echo %d > /sys/class/gpio/gpio%d/value", (unsigned __int8)blink_15605, 942);
  }
  system(cmd);
}
