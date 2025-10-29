int __fastcall sub_2F174(sem_t *a1, int a2, const char *a3, const char *a4, int a5)
{
  int result; // r0
  int v9; // r3
  struct timespec abstime; // [sp+10h] [bp-101Ch] BYREF
  _DWORD v11[2]; // [sp+18h] [bp-1014h] BYREF
  struct timeval v12; // [sp+20h] [bp-100Ch] BYREF
  char s[4056]; // [sp+28h] [bp-1004h] BYREF

  sub_2A7A4(&v12);
  v11[1] = 1000 * v12.tv_usec;
  v11[0] = v12.tv_sec;
  sub_2A558(&abstime);
  while ( 1 )
  {
    sub_2A5E0(&abstime.tv_sec, v11);
    result = sem_timedwait(a1, &abstime);
    if ( !result )
      break;
    v9 = *_errno_location();
    if ( v9 == 110 )
      return 110;
    if ( v9 != 4 )
    {
      snprintf(s, 0x1000u, "Failed to sem_timedwait errno=%d cgsem=0x%p in %s %s():%d", v9, a1, a3, a4, a5);
      sub_385C8(3, s, 1);
      sub_16BE0(1);
    }
  }
  return result;
}
