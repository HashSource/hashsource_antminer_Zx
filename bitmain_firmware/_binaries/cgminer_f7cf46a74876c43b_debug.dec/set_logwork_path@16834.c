char *__fastcall set_logwork_path(const char *arg)
{
  opt_set_charp(arg, &opt_logwork_path);
  return 0;
}
