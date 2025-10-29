int __fastcall cgsem_mswait(cgsem_t *cgsem, int ms, const char *file, const char *func, const int line)
{
  int v8; // r5
  __time_t tv_sec; // r10
  __syscall_slong_t v10; // r3
  __time_t v11; // r2
  bool v12; // cc
  __syscall_slong_t v13; // r1
  __time_t v14; // r0
  int result; // r0
  const char *v16; // r2
  timespec abs_timeout; // [sp+18h] [bp-1014h] BYREF
  timeval tv_now; // [sp+20h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+28h] [bp-1004h] BYREF

  gettimeofday(&tv_now, 0);
  v8 = 1000 * tv_now.tv_usec;
  tv_sec = tv_now.tv_sec;
  ms_to_timespec(&abs_timeout, tv_now.tv_usec, ms);
  while ( 1 )
  {
    v10 = abs_timeout.tv_nsec + v8;
    v11 = abs_timeout.tv_sec + tv_sec;
    v12 = abs_timeout.tv_nsec + v8 <= 999999999;
    abs_timeout.tv_sec += tv_sec;
    abs_timeout.tv_nsec += v8;
    if ( v12 )
    {
      if ( v10 < 0 )
      {
        do
        {
          v10 += 1000000000;
          --v11;
        }
        while ( v10 < 0 );
        abs_timeout.tv_sec = v11;
        abs_timeout.tv_nsec = v10;
      }
    }
    else
    {
      v13 = v10 - 1000000000;
      v14 = v11 + 1;
      if ( v10 - 1000000000 > 999999999 )
      {
        v13 = v10 - 2000000000;
        v14 = v11 + 2;
      }
      abs_timeout.tv_sec = v14;
      abs_timeout.tv_nsec = v13;
    }
    result = sem_timedwait(cgsem, &abs_timeout);
    if ( !result )
      break;
    result = *_errno_location();
    if ( result == 110 )
      break;
    if ( result != 4 )
    {
      LOWORD(v16) = 19796;
      HIWORD(v16) = (unsigned int)" %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v16, result, cgsem, file, func, line);
      applog(3, tmp42, 1);
      quit(1);
    }
  }
  return result;
}
