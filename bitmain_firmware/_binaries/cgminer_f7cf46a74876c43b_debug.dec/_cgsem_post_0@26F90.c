// Alternative name is '_cgsem_post.part.8'
void __fastcall __noreturn cgsem_post_0(cgsem_t *cgsem, const char *file, const char *func, const int line)
{
  int *v8; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v8 = _errno_location();
  snprintf(tmp42, 0x1000u, "Failed to sem_post errno=%d cgsem=0x%p in %s %s():%d", *v8, cgsem, file, func, line);
  applog(3, tmp42, 1);
  quit(1);
}
