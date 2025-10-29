// Alternative name is '_rd_lock.constprop.25'
void __fastcall rd_lock_0(pthread_rwlock_t *lock, const char *file, const char *func, const int line)
{
  int *v6; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_rwlock_rdlock(lock) )
  {
    v6 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v6, "api.c", file, func);
    applog(3, tmp42, 1);
    quit(1);
  }
}
