int __fastcall sub_18C10(int a1, unsigned int a2)
{
  __time_t v5; // r4
  signed int v6; // r1
  int v7; // r4
  struct timeval v9; // [sp+0h] [bp-10h] BYREF
  struct timespec abstime; // [sp+8h] [bp-8h] BYREF

  sub_2B13C(&v9);
  v5 = a2 / 0x3E8 + v9.tv_sec;
  v6 = 1000 * a2 - 1000000 * (a2 / 0x3E8) + v9.tv_usec;
  if ( v6 > 999999 )
  {
    ++v5;
    v6 -= 1000000;
  }
  abstime.tv_sec = v5;
  abstime.tv_nsec = 1000 * v6;
  if ( pthread_mutex_lock(&stru_63BCC) )
    sub_B4E4("restart_wait", 5227);
  if ( *(_BYTE *)(a1 + 62) )
    v7 = 0;
  else
    v7 = pthread_cond_timedwait(&cond, &stru_63BCC, &abstime);
  if ( pthread_mutex_unlock(&stru_63BCC) )
    sub_B694("restart_wait", 5232);
  off_60178();
  return v7;
}
