void __fastcall cgsem_init(cgsem_t *cgsem, const char *file, const char *func, const int line)
{
  int v7; // r0
  int v8; // r4
  int *v9; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v7 = sem_init(cgsem, 0, 0);
  if ( v7 )
  {
    v8 = v7;
    v9 = _errno_location();
    snprintf(tmp42, 0x1000u, "Failed to sem_init ret=%d errno=%d in %s %s():%d", v8, *v9, file, func, line);
    applog(3, tmp42, 1);
    quit(1);
  }
}
