int __fastcall sub_1842C(int a1, unsigned int a2)
{
  __time_t v5; // r4
  signed int v6; // r1
  int v7; // r4
  struct timeval v9; // [sp+0h] [bp-10h] BYREF
  struct timespec abstime; // [sp+8h] [bp-8h] BYREF

  sub_2A7A4(&v9);
  v5 = a2 / 0x3E8 + v9.tv_sec;
  v6 = 1000 * a2 - 1000000 * (a2 / 0x3E8) + v9.tv_usec;
  if ( v6 > 999999 )
  {
    ++v5;
    v6 -= 1000000;
  }
  abstime.tv_sec = v5;
  abstime.tv_nsec = 1000 * v6;
  if ( pthread_mutex_lock(&stru_78454) )
    sub_B35C("restart_wait", 5249);
  if ( *(_BYTE *)(a1 + 62) )
    v7 = 0;
  else
    v7 = pthread_cond_timedwait(&cond, &stru_78454, &abstime);
  if ( pthread_mutex_unlock(&stru_78454) )
    sub_B50C("restart_wait", 5254);
  off_72D18();
  return v7;
}
