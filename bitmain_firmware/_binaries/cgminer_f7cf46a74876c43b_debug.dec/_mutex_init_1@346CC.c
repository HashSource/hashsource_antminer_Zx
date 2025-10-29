// Alternative name is '_mutex_init.part.0.constprop.31'
void __fastcall __noreturn mutex_init_1(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v5; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v5 = _errno_location();
  snprintf(
    tmp42,
    0x1000u,
    "Failed to pthread_mutex_init errno=%d in %s %s():%d",
    *v5,
    "driver-btm-zcash.c",
    "bitmain_ZCASH_prepare",
    lock);
  applog(3, tmp42, 1);
  quit(1);
}
