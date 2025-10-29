int __fastcall inc_work_stats(int a1, int a2, int a3)
{
  const char *v6; // r2
  int v7; // r3
  int v8; // r1
  __int64 v9; // kr00_8
  int v10; // r4
  const char *v11; // r2
  int v12; // r3
  pool *v14; // r0

  if ( pthread_mutex_lock(&stats_lock) )
    mutex_lock((pthread_mutex_t *)(&_func___14527.__align + 4), (const char *)0x20C9, v6, v7);
  v8 = *(_DWORD *)(a1 + 36);
  v9 = *(_QWORD *)(v8 + 192) + a3;
  total_diff1 += a3;
  *(_QWORD *)(v8 + 192) = v9;
  if ( a2 )
  {
    *(_QWORD *)(a2 + 40) += a3;
  }
  else
  {
    v14 = current_pool();
    v14->diff1 += a3;
  }
  v10 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(v10 + 232) = time(0);
  if ( pthread_mutex_unlock(&stats_lock) )
    mutex_unlock_noyield((pthread_mutex_t *)(&_func___14527.__align + 4), (const char *)0x20D6, v11, v12);
  return selective_yield();
}
