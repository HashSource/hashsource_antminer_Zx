void __fastcall applog(int prio, const char *str, bool force)
{
  _BOOL4 v5; // r8
  struct tm *v6; // r0
  int v7; // r0
  FILE *v8; // r7
  size_t v9; // r0
  size_t v10; // r0
  time_t tmp_time; // [sp+1Ch] [bp-50h] BYREF
  timeval tv; // [sp+20h] [bp-4Ch] BYREF
  char datetime[64]; // [sp+28h] [bp-44h] BYREF

  if ( use_syslog )
  {
    syslog(prio | 0x80, "%s", str);
    return;
  }
  v5 = force;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  cgtime(&tv);
  tmp_time = tv.tv_sec;
  v6 = localtime(&tmp_time);
  snprintf(
    datetime,
    0x40u,
    " [%d-%02d-%02d %02d:%02d:%02d] ",
    v6->tm_year + 1900,
    v6->tm_mon + 1,
    v6->tm_mday,
    v6->tm_hour,
    v6->tm_min,
    v6->tm_sec);
  v7 = fileno((FILE *)stderr);
  if ( isatty(v7) )
  {
    if ( g_logfile_enable )
    {
LABEL_4:
      v8 = g_log_file;
      if ( g_log_file || (v8 = fopen(g_logfile_path, g_logfile_openflag), (g_log_file = v8) != 0) )
      {
        v9 = strlen(datetime);
        fwrite(datetime, v9, 1u, v8);
        v10 = strlen(str);
        fwrite(str, v10, 1u, g_log_file);
        fwrite(&word_58FE4, 1u, 1u, g_log_file);
        fflush(g_log_file);
      }
    }
  }
  else
  {
    fprintf((FILE *)stderr, "%s%s\n", datetime, str);
    fflush((FILE *)stderr);
    if ( g_logfile_enable )
      goto LABEL_4;
  }
  if ( prio == 3 || !opt_quiet )
    my_log_curses((pthread_mutex_t *)datetime, str, (const char *)v5, opt_quiet);
}
