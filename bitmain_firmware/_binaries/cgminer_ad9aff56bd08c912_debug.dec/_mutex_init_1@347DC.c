// Alternative name is '_mutex_init.part.0.constprop.31'
void __fastcall __noreturn mutex_init_1(pthread_mutex_t *lock, const char *file, const char *func, const int line)
{
  int *v5; // r0
  int v6; // r1
  const char *v7; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v5 = _errno_location();
  LOWORD(v6) = -32072;
  LOWORD(v7) = -1128;
  HIWORD(v6) = (unsigned int)"chain_acn%d" >> 16;
  HIWORD(v7) = (unsigned int)"NonceTime" >> 16;
  snprintf(tmp42, 0x1000u, v7, *v5, v6, "bitmain_ZCASH_prepare", lock);
  applog(3, tmp42, 1);
  quit(1);
}
