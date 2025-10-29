// Alternative name is 'my_log_curses.part.2'
void __fastcall my_log_curses(pthread_mutex_t *prio, const char *datetime, const char *str, bool force)
{
  pthread_mutex_t *v4; // r5
  const char *v6; // r1
  const char *v7; // r2
  int v8; // r3
  const char *v9; // r1
  const char *v10; // r2
  int v11; // r3

  v4 = prio;
  if ( str )
  {
    pthread_mutex_trylock(&console_lock);
    mutex_unlock_noyield_2((pthread_mutex_t *)0x26, v9, v10, v11);
    prio = (pthread_mutex_t *)selective_yield();
  }
  mutex_lock_2(prio, datetime, str, force);
  printf("%s%s%s", (const char *)v4, datetime, "                    \n");
  mutex_unlock_noyield_2((pthread_mutex_t *)0x31, v6, v7, v8);
  selective_yield();
}
