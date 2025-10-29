int set_phy_external_bist_result()
{
  char v1[128]; // [sp+0h] [bp-80h] BYREF

  memset(v1, 0, sizeof(v1));
  sprintf(v1, "<phy err cnt> %lld", 0LL);
  memset(v1, 0, sizeof(v1));
  sprintf(v1, "<phy lost cnt> %lld", 0LL);
  memset(v1, 0, sizeof(v1));
  sprintf(v1, "<phy lost lane num> %d", 0);
  memset(v1, 0, sizeof(v1));
  return sprintf(v1, "<phy err lane num> %d", 0);
}
