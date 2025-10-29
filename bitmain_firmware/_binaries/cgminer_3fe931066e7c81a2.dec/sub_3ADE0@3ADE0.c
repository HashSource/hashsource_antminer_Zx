void sub_3ADE0()
{
  char v0[4100]; // [sp+0h] [bp-1004h] BYREF

  snprintf(v0, 0x1000u, "%s: i2c always busy, break\n", "i2c_write");
  sub_38730(5, v0, 0);
}
