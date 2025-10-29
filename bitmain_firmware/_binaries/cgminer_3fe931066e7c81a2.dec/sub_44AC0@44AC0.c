int __fastcall sub_44AC0(int a1)
{
  char s[100]; // [sp+4h] [bp-64h] BYREF

  byte_76B68 ^= 1u;
  if ( a1 )
  {
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", 0, 942);
    system(s);
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", (unsigned __int8)byte_76B68, 941);
  }
  else
  {
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", 0, 941);
    system(s);
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", (unsigned __int8)byte_76B68, 942);
  }
  return system(s);
}
