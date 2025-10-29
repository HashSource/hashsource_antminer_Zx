double tsince_update()
{
  timeval now; // [sp+0h] [bp-Ch] BYREF

  cgtime(&now);
  return tdiff(&now, &update_tv_start);
}
