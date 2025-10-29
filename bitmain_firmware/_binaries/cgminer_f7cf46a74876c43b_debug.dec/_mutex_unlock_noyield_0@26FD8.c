// Alternative name is '_mutex_unlock_noyield.constprop.14'
void __fastcall mutex_unlock_noyield_0(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v6; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_unlock(lock) )
  {
    v6 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v6, "util.c", file, func);
    applog(3, tmp42, 1);
    quit(1);
  }
}
