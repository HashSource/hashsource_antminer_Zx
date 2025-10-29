int __fastcall sub_19A98(const char *a1)
{
  int result; // r0

  result = sub_196AC();
  if ( result )
  {
    wprintw((WINDOW *)dword_78258, "%s", a1);
    if ( pthread_mutex_unlock(&stru_785D0) )
      sub_B50C("unlock_curses", 2930);
    return off_72D18();
  }
  return result;
}
