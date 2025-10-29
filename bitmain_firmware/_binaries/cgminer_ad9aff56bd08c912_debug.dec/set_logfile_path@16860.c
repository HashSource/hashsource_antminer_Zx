char *__fastcall set_logfile_path(const char *arg)
{
  opt_set_charp(arg, &opt_logfile_path);
  return 0;
}
