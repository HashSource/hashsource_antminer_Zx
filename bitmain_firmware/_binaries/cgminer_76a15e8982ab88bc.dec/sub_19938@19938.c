int sub_19938()
{
  int result; // r0

  result = sub_196AC();
  if ( result )
  {
    werase((WINDOW *)stdscr);
    wclear((WINDOW *)dword_78258);
    if ( pthread_mutex_unlock(&stru_785D0) )
      sub_B50C("unlock_curses", 2930);
    return off_72D18();
  }
  return result;
}
