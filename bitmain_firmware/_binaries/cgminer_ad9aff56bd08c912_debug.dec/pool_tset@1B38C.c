int __fastcall pool_tset(int a1, _BYTE *a2)
{
  pthread_mutex_t *v2; // r4
  const char *v4; // r2
  int v5; // r3
  pthread_mutex_t *v6; // r0
  int v7; // r4
  const char *v8; // r2
  int v9; // r3

  v2 = (pthread_mutex_t *)(a1 + 220);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 220)) )
    mutex_lock((pthread_mutex_t *)&_func___14516, (const char *)0x304, v4, v5);
  v6 = v2;
  v7 = (unsigned __int8)*a2;
  *a2 = 1;
  if ( pthread_mutex_unlock(v6) )
    mutex_unlock_noyield((pthread_mutex_t *)&_func___14516, (const char *)0x307, v8, v9);
  selective_yield();
  return v7;
}
