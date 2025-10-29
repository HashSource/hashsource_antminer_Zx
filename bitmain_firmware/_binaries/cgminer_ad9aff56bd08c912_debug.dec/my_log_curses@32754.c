// Alternative name is 'my_log_curses.part.2'
void __fastcall my_log_curses(pthread_mutex_t *prio, const char *datetime, const char *str, bool force)
{
  pthread_mutex_t *v4; // r5
  int v6; // r3
  const char *v7; // r0
  const char *v8; // r1
  const char *v9; // r2
  int v10; // r3
  const char *v11; // r1
  const char *v12; // r2
  int v13; // r3

  v4 = prio;
  if ( str )
  {
    pthread_mutex_trylock(&console_lock);
    mutex_unlock_noyield_2((pthread_mutex_t *)0x26, v11, v12, v13);
    prio = (pthread_mutex_t *)selective_yield();
  }
  mutex_lock_2(prio, datetime, str, force);
  LOWORD(v6) = 26772;
  LOWORD(v7) = 18080;
  HIWORD(v6) = (unsigned int)"parameter" >> 16;
  HIWORD(v7) = (unsigned int)"ailed: %s" >> 16;
  printf(v7, v4, datetime, v6);
  mutex_unlock_noyield_2((pthread_mutex_t *)0x31, v8, v9, v10);
  selective_yield();
}
