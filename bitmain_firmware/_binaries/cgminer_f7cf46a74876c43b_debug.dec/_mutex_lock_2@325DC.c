// Alternative name is '_mutex_lock.constprop.4'
void __fastcall mutex_lock_2(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v4; // r0
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( pthread_mutex_lock(&console_lock) )
  {
    v4 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v4, "logging.c", "my_log_curses", 47);
    applog(3, tmp42, 1);
    quit(1);
  }
}
