// Alternative name is '_rwlock_init.constprop.25'
void __fastcall rwlock_init_1(pthread_rwlock_t *lock, const char *file, const char *func, const int line)
{
  int *v4; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_rwlock_init(lock, 0) )
  {
    v4 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "Failed to pthread_rwlock_init errno=%d in %s %s():%d",
      *v4,
      "driver-btm-zcash.c",
      "bitmain_ZCASH_prepare",
      7544);
    applog(3, tmp42, 1);
    quit(1);
  }
}
