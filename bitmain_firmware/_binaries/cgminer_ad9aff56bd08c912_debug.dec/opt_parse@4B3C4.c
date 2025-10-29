bool __fastcall opt_parse(int *argc, char **argv, void (*errlog)(const char *, ...))
{
  int v6; // r0
  unsigned int offset; // [sp+4h] [bp-8h] BYREF

  opt_argv0 = *argv;
  offset = 0;
  do
    v6 = parse_one(argc, argv, &offset, errlog);
  while ( v6 == 1 );
  return v6 == 0;
}
