char *__fastcall __noreturn opt_usage_and_exit(const char *extra)
{
  char *v1; // r0

  v1 = opt_usage(opt_argv0, extra);
  printf("%s", v1);
  fflush((FILE *)stdout);
  exit(0);
}
