// Alternative name is '_mutex_unlock_noyield.constprop.14'
void __fastcall mutex_unlock_noyield_0(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v6; // r0
  int v7; // r1
  const char *v8; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_unlock(lock) )
  {
    v6 = _errno_location();
    LOWORD(v7) = 15984;
    LOWORD(v8) = -920;
    HIWORD(v7) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v8) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v8, *v6, v7, file, func);
    applog(3, tmp42, 1);
    quit(1);
  }
}
