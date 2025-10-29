void __fastcall get_datestamp(char *f, size_t fsiz, timeval *tv)
{
  struct tm *v5; // r0
  const char *v6; // r2
  time_t tmp_time; // [sp+1Ch] [bp-4h] BYREF

  tmp_time = tv->tv_sec;
  v5 = localtime(&tmp_time);
  LOWORD(v6) = -2676;
  HIWORD(v6) = (unsigned int)"o malloc scratchbuf in scanhash_scrypt" >> 16;
  snprintf(f, fsiz, v6, v5->tm_year + 1900, v5->tm_mon + 1, v5->tm_mday, v5->tm_hour, v5->tm_min, v5->tm_sec);
}
