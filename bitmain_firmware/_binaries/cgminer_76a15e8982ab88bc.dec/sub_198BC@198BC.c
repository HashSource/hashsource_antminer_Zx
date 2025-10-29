int sub_198BC()
{
  int result; // r0
  int v1; // r2

  result = sub_196AC();
  if ( result )
  {
    if ( dword_78258 )
      v1 = *(__int16 *)(dword_78258 + 4);
    else
      v1 = -1;
    if ( dword_78258 )
      ++v1;
    wtouchln((WINDOW *)dword_78258, 0, v1, 1);
    wrefresh((WINDOW *)dword_78258);
    if ( pthread_mutex_unlock(&stru_785D0) )
      sub_B50C("unlock_curses", 2930);
    return off_72D18();
  }
  return result;
}
