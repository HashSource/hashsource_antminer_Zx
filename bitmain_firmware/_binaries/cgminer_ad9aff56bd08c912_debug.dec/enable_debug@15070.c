char *__fastcall enable_debug(bool *flag)
{
  *flag = 1;
  opt_log_output = 1;
  return 0;
}
