void sub_18068()
{
  int v0; // r2
  int v1; // r3
  int v2; // r1
  int v3; // r3
  int v4; // r2

  if ( byte_75DD0 && sub_17FE4() )
  {
    werase((WINDOW *)stdscr);
    if ( dword_7B7C0 )
      v0 = *(__int16 *)(dword_7B7C0 + 6);
    else
      v0 = -1;
    v1 = dword_7701C;
    if ( dword_7B7C0 )
      ++v0;
    if ( LINES - 1 <= dword_7701C )
      v1 = LINES - 2;
    dword_77020 = v1;
    dword_77024 = v1;
    wresize((WINDOW *)dword_7B7C0, v1, v0);
    v3 = dword_7BC90;
    if ( dword_7BC90 )
      v2 = *(__int16 *)(dword_7BC90 + 4);
    else
      v3 = -1;
    if ( dword_7BC90 )
      v4 = *(__int16 *)(v3 + 6);
    else
      v4 = v3;
    if ( dword_7BC90 )
    {
      v3 = v2 + 1;
      ++v4;
    }
    wresize((WINDOW *)dword_7B430, v3 - dword_77024, v4);
    mvwin((WINDOW *)dword_7B430, dword_77024, 0);
    if ( pthread_mutex_unlock(&mutex) )
      sub_B5C4("unlock_curses", 2930);
    off_75ED8();
  }
}
