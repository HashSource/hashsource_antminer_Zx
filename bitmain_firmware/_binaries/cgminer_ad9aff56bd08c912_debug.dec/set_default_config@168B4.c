char *__fastcall set_default_config(const char *arg)
{
  opt_set_charp(arg, &default_config);
  return 0;
}
