int sub_18B44()
{
  int result; // r0
  int v1; // r2

  result = sub_17FE4();
  if ( result )
  {
    if ( dword_7B430 )
      v1 = *(__int16 *)(dword_7B430 + 4);
    else
      v1 = -1;
    if ( dword_7B430 )
      ++v1;
    wtouchln((WINDOW *)dword_7B430, 0, v1, 1);
    wrefresh((WINDOW *)dword_7B430);
    if ( pthread_mutex_unlock(&mutex) )
      sub_B5C4("unlock_curses", 2930);
    return off_75ED8();
  }
  return result;
}
