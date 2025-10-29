void __cdecl simplelog(int prio, const char *str, bool force)
{
  int v3; // r0

  v3 = fileno((FILE *)stderr);
  if ( !isatty(v3) )
  {
    fprintf((FILE *)stderr, "%s\n", str);
    fflush((FILE *)stderr);
  }
  my_log_curses(prio, byte_36C3C, str, force);
}
