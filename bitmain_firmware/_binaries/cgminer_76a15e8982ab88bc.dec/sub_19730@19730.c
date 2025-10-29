void sub_19730()
{
  int v0; // r2
  int v1; // r3
  int v2; // r1
  int v3; // r3
  int v4; // r2

  if ( byte_72C1C && sub_196AC() )
  {
    werase((WINDOW *)stdscr);
    if ( dword_785E8 )
      v0 = *(__int16 *)(dword_785E8 + 6);
    else
      v0 = -1;
    v1 = dword_73E84;
    if ( dword_785E8 )
      ++v0;
    if ( LINES - 1 <= dword_73E84 )
      v1 = LINES - 2;
    dword_73E88 = v1;
    dword_73E8C = v1;
    wresize((WINDOW *)dword_785E8, v1, v0);
    v3 = dword_78AB8;
    if ( dword_78AB8 )
      v2 = *(__int16 *)(dword_78AB8 + 4);
    else
      v3 = -1;
    if ( dword_78AB8 )
      v4 = *(__int16 *)(v3 + 6);
    else
      v4 = v3;
    if ( dword_78AB8 )
    {
      v3 = v2 + 1;
      ++v4;
    }
    wresize((WINDOW *)dword_78258, v3 - dword_73E8C, v4);
    mvwin((WINDOW *)dword_78258, dword_73E8C, 0);
    if ( pthread_mutex_unlock(&stru_785D0) )
      sub_B50C("unlock_curses", 2930);
    off_72D18();
  }
}
