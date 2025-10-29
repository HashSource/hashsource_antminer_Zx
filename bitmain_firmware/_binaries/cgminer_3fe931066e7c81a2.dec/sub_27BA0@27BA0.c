int sub_27BA0()
{
  int maxy; // r6
  WINDOW *v1; // r0
  int maxx; // r1

  if ( pthread_mutex_lock(&mutex) )
    sub_B414("lock_curses", 2935);
  if ( byte_77018 )
  {
    if ( !pthread_mutex_unlock(&mutex) )
      return off_75ED8();
LABEL_14:
    sub_B5C4("unlock_curses", 2930);
  }
  v1 = initscr();
  dword_7BC90 = (int)v1;
  if ( v1 )
    maxx = v1->_maxx;
  else
    maxy = -1;
  if ( v1 )
    maxy = v1->_maxy;
  else
    maxx = maxy;
  if ( v1 )
  {
    ++maxx;
    ++maxy;
  }
  dword_7B7C0 = (int)newwin(dword_7701C, maxx, 0, 0);
  leaveok((WINDOW *)dword_7B7C0, 1);
  dword_7B430 = (int)newwin(maxy - dword_77024, 0, dword_77024, 0);
  idlok((WINDOW *)dword_7B430, 1);
  scrollok((WINDOW *)dword_7B430, 1);
  leaveok((WINDOW *)dword_7B430, 1);
  cbreak();
  noecho();
  byte_77018 = 1;
  dword_77020 = dword_7701C;
  if ( pthread_mutex_unlock(&mutex) )
    goto LABEL_14;
  return off_75ED8();
}
