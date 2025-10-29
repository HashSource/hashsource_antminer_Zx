char *__fastcall arg_bad(const char *fmt, const char *arg)
{
  size_t v4; // r5
  size_t v5; // r0
  char *v6; // r5

  v4 = strlen(fmt);
  v5 = strlen(arg);
  v6 = (char *)malloc(v5 + v4);
  sprintf(v6, fmt, arg);
  return v6;
}
