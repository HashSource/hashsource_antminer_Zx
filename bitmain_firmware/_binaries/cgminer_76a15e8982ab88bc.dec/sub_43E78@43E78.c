int __fastcall sub_43E78(int a1)
{
  char s[100]; // [sp+4h] [bp-64h] BYREF

  byte_739A4 ^= 1u;
  if ( a1 )
  {
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", 0, 942);
    system(s);
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", (unsigned __int8)byte_739A4, 941);
  }
  else
  {
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", 0, 941);
    system(s);
    sprintf(s, "echo %d > /sys/class/gpio/gpio%d/value", (unsigned __int8)byte_739A4, 942);
  }
  return system(s);
}
