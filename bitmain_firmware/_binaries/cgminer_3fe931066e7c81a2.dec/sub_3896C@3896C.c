int __fastcall sub_3896C(int a1)
{
  int result; // r0
  int *v3; // r0
  char s[4096]; // [sp+10h] [bp-1000h] BYREF

  result = pthread_mutex_unlock(&mutex);
  if ( result )
  {
    v3 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v3, "logging.c", "my_log_curses", a1);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  return result;
}
