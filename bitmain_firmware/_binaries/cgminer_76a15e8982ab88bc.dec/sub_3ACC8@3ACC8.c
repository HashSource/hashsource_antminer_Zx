int sub_3ACC8()
{
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  snprintf(s, 0x1000u, "%s input param error: str length = %u\n", "bm1740_makeup_get_status_cmd", 9);
  sub_385C8(3, s, 0);
  return -1;
}
