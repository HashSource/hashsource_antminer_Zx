// Alternative name is '_cgsem_post.part.8'
void __fastcall __noreturn cgsem_post_0(cgsem_t *cgsem, const char *file, const char *func, const int line)
{
  int *v8; // r0
  const char *v9; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v8 = _errno_location();
  LOWORD(v9) = 15928;
  HIWORD(v9) = (unsigned int)"ing with %s:%s HTTP proxy" >> 16;
  snprintf(tmp42, 0x1000u, v9, *v8, cgsem, file, func, line);
  applog(3, tmp42, 1);
  quit(1);
}
