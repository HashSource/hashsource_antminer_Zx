char *__fastcall set_url(char *arg)
{
  pool *v2; // r0

  v2 = add_url();
  setup_url(v2, arg);
  return 0;
}
