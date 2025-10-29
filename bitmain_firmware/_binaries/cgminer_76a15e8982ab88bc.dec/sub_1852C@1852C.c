int sub_1852C()
{
  if ( pthread_mutex_lock((pthread_mutex_t *)dword_73E6C) )
    sub_B35C("wake_gws", 5204);
  pthread_cond_signal(&stru_77FC8);
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_73E6C) )
    sub_B50C("wake_gws", 5206);
  return off_72D18();
}
