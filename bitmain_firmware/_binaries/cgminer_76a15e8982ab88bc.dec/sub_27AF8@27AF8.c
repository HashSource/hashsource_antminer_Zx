int sub_27AF8()
{
  int maxy; // r6
  WINDOW *v1; // r0
  int maxx; // r1

  if ( pthread_mutex_lock(&stru_785D0) )
    sub_B35C("lock_curses", 2935);
  if ( byte_73E80 )
  {
    if ( !pthread_mutex_unlock(&stru_785D0) )
      return off_72D18();
LABEL_14:
    sub_B50C("unlock_curses", 2930);
  }
  v1 = initscr();
  dword_78AB8 = (int)v1;
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
  dword_785E8 = (int)newwin(dword_73E84, maxx, 0, 0);
  leaveok((WINDOW *)dword_785E8, 1);
  dword_78258 = (int)newwin(maxy - dword_73E8C, 0, dword_73E8C, 0);
  idlok((WINDOW *)dword_78258, 1);
  scrollok((WINDOW *)dword_78258, 1);
  leaveok((WINDOW *)dword_78258, 1);
  cbreak();
  noecho();
  byte_73E80 = 1;
  dword_73E88 = dword_73E84;
  if ( pthread_mutex_unlock(&stru_785D0) )
    goto LABEL_14;
  return off_72D18();
}
