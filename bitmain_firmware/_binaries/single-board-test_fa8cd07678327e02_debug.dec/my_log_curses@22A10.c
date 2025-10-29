void __cdecl my_log_curses(int prio, const char *datetime, const char *str, bool force)
{
  if ( !opt_quiet || !prio )
  {
    if ( force )
    {
      pthread_mutex_trylock(&console_lock);
      pthread_mutex_unlock(&console_lock);
    }
    pthread_mutex_lock(&console_lock);
    if ( prio )
    {
      if ( prio == 1 )
        fprintf((FILE *)stderr, "\x1B[1;34m%s%s\x1B[0m", datetime, str);
      else
        fprintf((FILE *)stderr, "%s%s", datetime, str);
    }
    else
    {
      fprintf((FILE *)stderr, "\x1B[0;31m%s%s\x1B[0m", datetime, str);
    }
    fflush((FILE *)stderr);
    pthread_mutex_unlock(&console_lock);
  }
}
