int __fastcall sub_199A4(int a1, const char *a2, const char *a3)
{
  int result; // r0
  _BOOL4 v7; // r4
  int v8; // r2

  result = sub_196AC();
  if ( !result )
    return result;
  v7 = (unsigned int)(a1 - 3) <= 1;
  if ( byte_788F0 )
  {
    if ( v7 )
    {
      wprintw((WINDOW *)dword_78258, "%s%s\n", a2, a3);
LABEL_5:
      if ( dword_78258 )
        v8 = *(__int16 *)(dword_78258 + 4);
      else
        v8 = -1;
      if ( dword_78258 )
        ++v8;
      wtouchln((WINDOW *)dword_78258, 0, v8, 1);
      wrefresh((WINDOW *)dword_78258);
    }
  }
  else
  {
    wprintw((WINDOW *)dword_78258, "%s%s\n", a2, a3);
    if ( v7 )
      goto LABEL_5;
  }
  if ( pthread_mutex_unlock(&stru_785D0) )
    sub_B50C("unlock_curses", 2930);
  off_72D18();
  return 1;
}
