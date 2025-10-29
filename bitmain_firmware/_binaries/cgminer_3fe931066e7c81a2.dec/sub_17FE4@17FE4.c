int sub_17FE4()
{
  int v0; // r4

  if ( pthread_mutex_lock(&mutex) )
    sub_B414("lock_curses", 2935);
  v0 = (unsigned __int8)byte_77018;
  if ( byte_77018 )
    return (unsigned __int8)byte_77018;
  if ( pthread_mutex_unlock(&mutex) )
    sub_B5C4("unlock_curses", 2930);
  off_75ED8();
  return v0;
}
