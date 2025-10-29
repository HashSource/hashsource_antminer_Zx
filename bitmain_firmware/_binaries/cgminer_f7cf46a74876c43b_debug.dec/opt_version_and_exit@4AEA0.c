char *__fastcall __noreturn opt_version_and_exit(const char *version)
{
  puts(version);
  fflush((FILE *)stdout);
  exit(0);
}
