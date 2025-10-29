// Alternative name is '_mutex_lock.part.1.constprop.15'
void __fastcall __noreturn mutex_lock_0(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v6; // r0
  const char *v7; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v6 = _errno_location();
  LOWORD(v7) = -968;
  HIWORD(v7) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
  snprintf(tmp42, 0x1000u, v7, *v6, "util.c", lock, file);
  applog(3, tmp42, 1);
  quit(1);
}
