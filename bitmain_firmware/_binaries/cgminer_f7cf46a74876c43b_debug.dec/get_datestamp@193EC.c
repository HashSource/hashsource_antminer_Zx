void __fastcall get_datestamp(char *f, size_t fsiz, timeval *tv)
{
  struct tm *v5; // r0
  time_t tmp_time; // [sp+1Ch] [bp-4h] BYREF

  tmp_time = tv->tv_sec;
  v5 = localtime(&tmp_time);
  snprintf(
    f,
    fsiz,
    "[%d-%02d-%02d %02d:%02d:%02d]",
    v5->tm_year + 1900,
    v5->tm_mon + 1,
    v5->tm_mday,
    v5->tm_hour,
    v5->tm_min,
    v5->tm_sec);
}
