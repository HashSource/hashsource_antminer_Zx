void __fastcall simplelog(int prio, const char *str, bool force)
{
  _BOOL4 v5; // r7
  int v6; // r0
  bool v8; // [sp+0h] [bp-4h]

  if ( use_syslog )
  {
    j_syslog(prio | 0x80, "%s", str);
  }
  else
  {
    v5 = force;
    v6 = fileno((FILE *)stderr);
    if ( !isatty(v6) )
    {
      fprintf((FILE *)stderr, "%s\n", str);
      fflush((FILE *)stderr);
    }
    if ( prio == 3 || !opt_quiet )
      my_log_curses((pthread_mutex_t *)&byte_59398, str, (const char *)v5, v8);
  }
}
