void __cdecl applog(int prio, const char *str, bool force)
{
  int v3; // r0
  char datetime[64]; // [sp+2Ch] [bp+14h] BYREF
  time_t tmp_time; // [sp+6Ch] [bp+54h] BYREF
  timeval tv; // [sp+70h] [bp+58h] BYREF
  tm *tm; // [sp+78h] [bp+60h]
  int ms; // [sp+7Ch] [bp+64h]

  tv.tv_sec = 0;
  tv.tv_usec = 0;
  gettimeofday(&tv, 0);
  tmp_time = tv.tv_sec;
  ms = tv.tv_usec / 1000;
  tm = localtime(&tmp_time);
  snprintf(
    datetime,
    0x40u,
    " [%d-%02d-%02d %02d:%02d:%02d.%03d] ",
    tm->tm_year + 1900,
    tm->tm_mon + 1,
    tm->tm_mday,
    tm->tm_hour,
    tm->tm_min,
    tm->tm_sec,
    ms);
  if ( app_conf->dbg_fp )
  {
    v3 = fileno(app_conf->dbg_fp);
    if ( !isatty(v3) )
    {
      fprintf(app_conf->dbg_fp, "%s%s", datetime, str);
      fflush(app_conf->dbg_fp);
    }
  }
  if ( app_conf->work_mode != 1 )
    my_log_curses(prio, datetime, str, force);
}
