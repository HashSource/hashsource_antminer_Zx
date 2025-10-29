void __noreturn kill_work()
{
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  cg_completion_timeout(_kill_work, 0, 5000);
  strcpy(tmp42, "Shutdown signal received.");
  applog(3, tmp42, 1);
  _quit(0, 1);
}
