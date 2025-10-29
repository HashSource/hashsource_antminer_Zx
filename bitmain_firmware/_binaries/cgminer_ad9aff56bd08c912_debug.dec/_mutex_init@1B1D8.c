// Alternative name is '_mutex_init.part.39.constprop.66'
void __fastcall __noreturn mutex_init(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v6; // r0
  const char *v7; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v6 = _errno_location();
  LOWORD(v7) = -1128;
  HIWORD(v7) = (unsigned int)"NonceTime" >> 16;
  snprintf(tmp42, 0x1000u, v7, *v6, "cgminer.c", lock, file);
  applog(3, tmp42, 1);
  _quit(1, 1);
}
