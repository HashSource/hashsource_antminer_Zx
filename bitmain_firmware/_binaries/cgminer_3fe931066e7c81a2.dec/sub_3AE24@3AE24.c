int sub_3AE24()
{
  char v1[4100]; // [sp+0h] [bp-1004h] BYREF

  snprintf(v1, 0x1000u, "%s: i2c always busy, break\n", "i2c_read");
  sub_38730(5, v1, 0);
  return 255;
}
