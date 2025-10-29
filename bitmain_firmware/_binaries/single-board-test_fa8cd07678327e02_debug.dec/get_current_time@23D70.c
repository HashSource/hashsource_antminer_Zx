void __cdecl get_current_time(char *dtime)
{
  time_t tmp_time; // [sp+24h] [bp+Ch] BYREF
  timeval tv; // [sp+28h] [bp+10h] BYREF
  char datetime[64]; // [sp+30h] [bp+18h] BYREF
  tm *tm; // [sp+70h] [bp+58h]
  int ms; // [sp+74h] [bp+5Ch]

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
  strcpy(dtime, datetime);
}
