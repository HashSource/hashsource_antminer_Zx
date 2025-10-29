void __fastcall cgsem_wait(cgsem_t *cgsem, const char *file, const char *func, const int line)
{
  int v8; // r3
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  while ( sem_wait(cgsem) )
  {
    v8 = *_errno_location();
    if ( v8 != 4 )
    {
      snprintf(tmp42, 0x1000u, "Failed to sem_wait errno=%d cgsem=0x%p in %s %s():%d", v8, cgsem, file, func, line);
      applog(3, tmp42, 1);
      quit(1);
    }
  }
}
