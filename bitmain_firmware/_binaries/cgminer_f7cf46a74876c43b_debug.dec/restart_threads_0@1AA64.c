// Alternative name is 'restart_threads.part.56'
void __noreturn restart_threads_0()
{
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  strcpy(tmp42, "Failed to create restart thread");
  applog(3, tmp42, 1);
  _quit(1, 1);
}
