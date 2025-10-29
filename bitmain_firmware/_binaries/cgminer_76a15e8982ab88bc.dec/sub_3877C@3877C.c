int sub_3877C()
{
  int result; // r0
  int *v1; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  result = pthread_mutex_lock(&stru_785D0);
  if ( result )
  {
    v1 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v1, "logging.c", "my_log_curses", 47);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  return result;
}
