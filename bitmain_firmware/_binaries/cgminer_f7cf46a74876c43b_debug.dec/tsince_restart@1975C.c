double tsince_restart()
{
  timeval now; // [sp+0h] [bp-Ch] BYREF

  cgtime(&now);
  return tdiff(&now, &restart_tv_start);
}
