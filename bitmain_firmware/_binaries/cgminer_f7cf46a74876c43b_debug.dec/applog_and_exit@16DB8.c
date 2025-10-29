void __noreturn applog_and_exit(const char *a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  vsnprintf(exit_buf, 0x200u, a1, varg_r1);
  applog(3, exit_buf, 1);
  exit(1);
}
