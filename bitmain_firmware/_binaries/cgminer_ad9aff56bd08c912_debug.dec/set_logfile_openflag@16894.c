char *__fastcall set_logfile_openflag(const char *arg)
{
  opt_set_charp(arg, &opt_logfile_openflag);
  return 0;
}
