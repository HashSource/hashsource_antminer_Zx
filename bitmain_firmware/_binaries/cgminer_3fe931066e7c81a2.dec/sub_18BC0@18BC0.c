int __fastcall sub_18BC0(const char *a1)
{
  int result; // r0

  result = sub_17FE4();
  if ( result )
  {
    wprintw((WINDOW *)dword_7B430, "%s", a1);
    if ( pthread_mutex_unlock(&mutex) )
      sub_B5C4("unlock_curses", 2930);
    return off_75ED8();
  }
  return result;
}
