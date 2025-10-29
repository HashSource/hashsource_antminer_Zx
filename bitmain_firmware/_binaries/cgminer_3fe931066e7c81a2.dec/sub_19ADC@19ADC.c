int sub_19ADC()
{
  pthread_mutex_trylock(&mutex);
  if ( !byte_77018 )
  {
    if ( !pthread_mutex_unlock(&mutex) )
      return off_75ED8();
LABEL_5:
    sub_B5C4("unlock_curses", 2930);
  }
  byte_75DD0 = 0;
  byte_77018 = 0;
  leaveok((WINDOW *)dword_7B430, 0);
  leaveok((WINDOW *)dword_7B7C0, 0);
  leaveok((WINDOW *)dword_7BC90, 0);
  nocbreak();
  echo();
  delwin((WINDOW *)dword_7B430);
  delwin((WINDOW *)dword_7B7C0);
  delwin((WINDOW *)dword_7BC90);
  endwin();
  if ( pthread_mutex_unlock(&mutex) )
    goto LABEL_5;
  return off_75ED8();
}
