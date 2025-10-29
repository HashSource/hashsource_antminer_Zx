int sub_196AC()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_785D0) )
    sub_B35C("lock_curses", 2935);
  v0 = (unsigned __int8)byte_73E80;
  if ( byte_73E80 )
    return (unsigned __int8)byte_73E80;
  if ( pthread_mutex_unlock(&stru_785D0) )
    sub_B50C("unlock_curses", 2930);
  off_72D18();
  return v0;
}
