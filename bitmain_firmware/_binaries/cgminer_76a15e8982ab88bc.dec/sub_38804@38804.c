int __fastcall sub_38804(int a1)
{
  int result; // r0
  int *v3; // r0
  char s[4096]; // [sp+10h] [bp-1000h] BYREF

  result = pthread_mutex_unlock(&stru_785D0);
  if ( result )
  {
    v3 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v3, "logging.c", "my_log_curses", a1);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  return result;
}
