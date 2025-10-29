void __fastcall __noreturn opt_verusage_and_exit(const char *a1)
{
  char *v2; // r0

  printf("%s\nBuilt with bitmain_zcash mining support.\n", packagename);
  v2 = opt_usage(opt_argv0, a1);
  printf("%s", v2);
  fflush((FILE *)stdout);
  exit(0);
}
