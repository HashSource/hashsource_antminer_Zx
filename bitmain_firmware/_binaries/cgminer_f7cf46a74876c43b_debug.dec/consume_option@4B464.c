void __fastcall consume_option(int *argc, char **argv, unsigned int optnum)
{
  memmove(&argv[optnum], &argv[optnum + 1], 4 * (*argc - optnum));
  --*argc;
}
