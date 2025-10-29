int __fastcall inc_dev_status(int a1, int a2)
{
  const char *v4; // r2
  int v5; // r3
  const char *v6; // r2
  int v7; // r3

  if ( pthread_mutex_lock(&stats_lock) )
    mutex_lock((pthread_mutex_t *)&_func___16532, (const char *)0x2081, v4, v5);
  g_max_fan = a1;
  g_max_temp = a2;
  if ( pthread_mutex_unlock(&stats_lock) )
    mutex_unlock_noyield((pthread_mutex_t *)&_func___16532, (const char *)0x2084, v6, v7);
  return selective_yield();
}
