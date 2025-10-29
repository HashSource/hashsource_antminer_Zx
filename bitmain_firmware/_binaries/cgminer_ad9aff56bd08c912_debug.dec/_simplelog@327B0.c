void __fastcall simplelog(int prio, const char *str, bool force)
{
  _BOOL4 v5; // r7
  int v6; // r0
  pthread_mutex_t *v8; // r0
  const char *v9; // r1
  const char *v10; // r1
  bool v11; // [sp+0h] [bp-4h]

  if ( use_syslog )
  {
    LOWORD(v9) = 20752;
    HIWORD(v9) = (unsigned int)"mcast join failed (%s)%s" >> 16;
    j_syslog(prio | 0x80, v9, str);
  }
  else
  {
    v5 = force;
    v6 = fileno((FILE *)stderr);
    if ( !isatty(v6) )
    {
      LOWORD(v10) = -31316;
      HIWORD(v10) = (unsigned int)"ailed!" >> 16;
      fprintf((FILE *)stderr, v10, str);
      fflush((FILE *)stderr);
    }
    if ( prio == 3 || !opt_quiet )
    {
      LOWORD(v8) = -27628;
      HIWORD(v8) = (unsigned int)"c.txt" >> 16;
      my_log_curses(v8, str, (const char *)v5, v11);
    }
  }
}
