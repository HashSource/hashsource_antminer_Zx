// Alternative name is '_rw_unlock.part.36.constprop.79'
void __fastcall __noreturn rw_unlock(pthread_rwlock_t *lock, const char *file, const char *func, const int line)
{
  int *v6; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v6 = _errno_location();
  snprintf(
    tmp42,
    0x1000u,
    "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
    *v6,
    "cgminer.c",
    (const char *)lock,
    file);
  applog(3, tmp42, 1);
  _quit(1, 1);
}
