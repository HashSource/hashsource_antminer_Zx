char *__fastcall set_version_path(const char *arg)
{
  opt_set_charp(arg, &opt_version_path);
  return 0;
}
