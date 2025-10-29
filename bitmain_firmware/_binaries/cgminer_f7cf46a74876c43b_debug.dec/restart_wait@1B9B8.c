int __fastcall restart_wait(int a1, unsigned int a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r1
  __time_t v6; // r4
  int v7; // r1
  const char *v8; // r2
  int v9; // r3
  int v10; // r4
  const char *v11; // r2
  int v12; // r3
  timeval v14; // [sp+0h] [bp-10h] BYREF
  struct timespec abstime; // [sp+8h] [bp-8h] BYREF

  v4 = a2 / 0x3E8;
  cgtime(&v14);
  v5 = 1000 * a2 - 1000000 * v4;
  v6 = v4 + v14.tv_sec;
  v7 = v5 + v14.tv_usec;
  if ( v7 > 999999 )
  {
    ++v6;
    v7 -= 1000000;
  }
  abstime.tv_sec = v6;
  abstime.tv_nsec = 1000 * v7;
  v10 = pthread_mutex_lock(&restart_lock);
  if ( v10 )
    mutex_lock((pthread_mutex_t *)&_func___15752, (const char *)0x1481, v8, v9);
  if ( !*(_BYTE *)(a1 + 62) )
    v10 = pthread_cond_timedwait(&restart_cond, &restart_lock, &abstime);
  if ( pthread_mutex_unlock(&restart_lock) )
    mutex_unlock_noyield((pthread_mutex_t *)&_func___15752, (const char *)0x1486, v11, v12);
  selective_yield();
  return v10;
}
