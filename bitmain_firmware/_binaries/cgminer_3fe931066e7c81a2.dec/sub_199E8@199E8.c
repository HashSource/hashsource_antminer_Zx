int __fastcall sub_199E8(int a1, const char *a2, const char *a3)
{
  int result; // r0
  _BOOL4 v7; // r4
  int v8; // r2

  result = sub_17FE4();
  if ( !result )
    return result;
  v7 = (unsigned int)(a1 - 3) <= 1;
  if ( byte_7BAC8 )
  {
    if ( v7 )
    {
      wprintw((WINDOW *)dword_7B430, "%s%s\n", a2, a3);
LABEL_5:
      if ( dword_7B430 )
        v8 = *(__int16 *)(dword_7B430 + 4);
      else
        v8 = -1;
      if ( dword_7B430 )
        ++v8;
      wtouchln((WINDOW *)dword_7B430, 0, v8, 1);
      wrefresh((WINDOW *)dword_7B430);
    }
  }
  else
  {
    wprintw((WINDOW *)dword_7B430, "%s%s\n", a2, a3);
    if ( v7 )
      goto LABEL_5;
  }
  if ( pthread_mutex_unlock(&mutex) )
    sub_B5C4("unlock_curses", 2930);
  off_75ED8();
  return 1;
}
