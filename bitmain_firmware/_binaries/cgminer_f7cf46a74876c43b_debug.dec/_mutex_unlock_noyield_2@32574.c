// Alternative name is '_mutex_unlock_noyield.constprop.3'
void __fastcall mutex_unlock_noyield_2(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v5; // r0
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( pthread_mutex_unlock(&console_lock) )
  {
    v5 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v5,
      "logging.c",
      "my_log_curses",
      lock);
    applog(3, tmp42, 1);
    quit(1);
  }
}
