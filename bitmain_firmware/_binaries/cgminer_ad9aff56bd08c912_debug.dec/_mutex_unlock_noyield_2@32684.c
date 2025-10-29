// Alternative name is '_mutex_unlock_noyield.constprop.3'
void __fastcall mutex_unlock_noyield_2(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v5; // r0
  int v6; // r1
  int v7; // r3
  const char *v8; // r2
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( pthread_mutex_unlock(&console_lock) )
  {
    v5 = _errno_location();
    LOWORD(v6) = 26760;
    v7 = *v5;
    LOWORD(v5) = 26704;
    HIWORD(v6) = (unsigned int)"ing hotplug parameter" >> 16;
    HIWORD(v5) = (unsigned int)"" >> 16;
    LOWORD(v8) = -920;
    HIWORD(v8) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v8, v7, v6, v5, lock);
    applog(3, tmp42, 1);
    quit(1);
  }
}
