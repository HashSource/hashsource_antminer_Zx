int sub_18AD8()
{
  int result; // r0

  result = sub_17FE4();
  if ( result )
  {
    werase((WINDOW *)stdscr);
    wclear((WINDOW *)dword_7B430);
    if ( pthread_mutex_unlock(&mutex) )
      sub_B5C4("unlock_curses", 2930);
    return off_75ED8();
  }
  return result;
}
