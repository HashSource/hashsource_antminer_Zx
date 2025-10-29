void __fastcall applog(int prio, const char *str, bool force)
{
  _BOOL4 v5; // r8
  struct tm *v6; // r0
  const char *v7; // r2
  int v8; // r0
  FILE *v9; // r7
  size_t v10; // r0
  size_t v11; // r0
  const void *v12; // r0
  const char *v14; // r1
  const char *v15; // r1
  time_t tmp_time; // [sp+1Ch] [bp-50h] BYREF
  timeval tv; // [sp+20h] [bp-4Ch] BYREF
  char datetime[64]; // [sp+28h] [bp-44h] BYREF

  if ( use_syslog )
  {
    LOWORD(v14) = 20752;
    HIWORD(v14) = (unsigned int)"mcast join failed (%s)%s" >> 16;
    syslog(prio | 0x80, v14, str);
    return;
  }
  v5 = force;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  cgtime(&tv);
  tmp_time = tv.tv_sec;
  v6 = localtime(&tmp_time);
  LOWORD(v7) = 26720;
  HIWORD(v7) = (unsigned int)"bled" >> 16;
  snprintf(datetime, 0x40u, v7, v6->tm_year + 1900, v6->tm_mon + 1, v6->tm_mday, v6->tm_hour, v6->tm_min, v6->tm_sec);
  v8 = fileno((FILE *)stderr);
  if ( isatty(v8) )
  {
    if ( g_logfile_enable )
    {
LABEL_4:
      v9 = g_log_file;
      if ( g_log_file || (v9 = fopen(g_logfile_path, g_logfile_openflag), (g_log_file = v9) != 0) )
      {
        v10 = strlen(datetime);
        fwrite(datetime, v10, 1u, v9);
        v11 = strlen(str);
        fwrite(str, v11, 1u, g_log_file);
        LOWORD(v12) = -28576;
        HIWORD(v12) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
        fwrite(v12, 1u, 1u, g_log_file);
        fflush(g_log_file);
      }
    }
  }
  else
  {
    LOWORD(v15) = 26752;
    HIWORD(v15) = (unsigned int)"" >> 16;
    fprintf((FILE *)stderr, v15, datetime, str);
    fflush((FILE *)stderr);
    if ( g_logfile_enable )
      goto LABEL_4;
  }
  if ( prio == 3 || !opt_quiet )
    my_log_curses((pthread_mutex_t *)datetime, str, (const char *)v5, opt_quiet);
}
