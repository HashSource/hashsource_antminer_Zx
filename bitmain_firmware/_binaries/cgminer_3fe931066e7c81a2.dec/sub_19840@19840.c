int sub_19840()
{
  if ( pthread_mutex_lock((pthread_mutex_t *)dword_7704C) )
    sub_B414("wake_gws", 5204);
  pthread_cond_signal(&stru_7B1A0);
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_7704C) )
    sub_B5C4("wake_gws", 5206);
  return off_75ED8();
}
