char *__fastcall opt_invalid_argument(const char *arg)
{
  size_t v2; // r0
  char *v3; // r4

  v2 = strlen(arg);
  v3 = (char *)malloc(v2 + 22);
  sprintf(v3, "Invalid argument '%s'", arg);
  return v3;
}
