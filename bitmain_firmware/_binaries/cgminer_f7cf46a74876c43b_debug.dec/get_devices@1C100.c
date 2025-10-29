cgpu_info *__fastcall get_devices(int a1)
{
  const char *v2; // r2
  int v3; // r3
  cgpu_info *v4; // r4
  const char *v5; // r2
  int v6; // r3

  if ( pthread_rwlock_rdlock(&devices_lock) )
    rd_lock((pthread_rwlock_t *)&_func___14460, (const char *)0x278, v2, v3);
  v4 = devices[a1];
  if ( pthread_rwlock_unlock(&devices_lock) )
    rw_unlock((pthread_rwlock_t *)&_func___14460, (const char *)0x27A, v5, v6);
  selective_yield();
  return v4;
}
