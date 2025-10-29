int sub_388E4()
{
  int result; // r0
  int *v1; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  result = pthread_mutex_lock(&mutex);
  if ( result )
  {
    v1 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v1, "logging.c", "my_log_curses", 47);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  return result;
}
