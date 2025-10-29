// Alternative name is '_mutex_lock.constprop.4'
void __fastcall mutex_lock_2(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v4; // r0
  int v5; // r1
  int v6; // r3
  const char *v7; // r2
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( pthread_mutex_lock(&console_lock) )
  {
    v4 = _errno_location();
    LOWORD(v5) = 26760;
    v6 = *v4;
    LOWORD(v4) = 26704;
    HIWORD(v5) = (unsigned int)"ing hotplug parameter" >> 16;
    HIWORD(v4) = (unsigned int)"" >> 16;
    LOWORD(v7) = -968;
    HIWORD(v7) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v7, v6, v5, v4, 47);
    applog(3, tmp42, 1);
    quit(1);
  }
}
