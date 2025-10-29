int sub_195CC()
{
  pthread_mutex_trylock(&stru_785D0);
  if ( !byte_73E80 )
  {
    if ( !pthread_mutex_unlock(&stru_785D0) )
      return off_72D18();
LABEL_5:
    sub_B50C("unlock_curses", 2930);
  }
  byte_72C1C = 0;
  byte_73E80 = 0;
  leaveok((WINDOW *)dword_78258, 0);
  leaveok((WINDOW *)dword_785E8, 0);
  leaveok((WINDOW *)dword_78AB8, 0);
  nocbreak();
  echo();
  delwin((WINDOW *)dword_78258);
  delwin((WINDOW *)dword_785E8);
  delwin((WINDOW *)dword_78AB8);
  endwin();
  if ( pthread_mutex_unlock(&stru_785D0) )
    goto LABEL_5;
  return off_72D18();
}
