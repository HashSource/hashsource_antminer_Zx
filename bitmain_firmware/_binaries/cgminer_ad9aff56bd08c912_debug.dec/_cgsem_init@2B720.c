void __fastcall cgsem_init(cgsem_t *cgsem, const char *file, const char *func, const int line)
{
  int v7; // r0
  int v8; // r4
  int *v9; // r0
  const char *v10; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v7 = sem_init(cgsem, 0, 0);
  if ( v7 )
  {
    v8 = v7;
    v9 = _errno_location();
    LOWORD(v10) = 19688;
    HIWORD(v10) = (unsigned int)"Failed to malloc in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v10, v8, *v9, file, func, line);
    applog(3, tmp42, 1);
    quit(1);
  }
}
