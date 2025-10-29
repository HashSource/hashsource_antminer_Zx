void __fastcall sub_19840(int a1, int a2)
{
  int v2; // r2

  if ( byte_78768 )
  {
    v2 = dword_73E90;
  }
  else
  {
    v2 = dword_73E94;
    a2 = dword_73E90;
  }
  if ( !byte_78768 )
    v2 += a2;
  dword_73E84 = v2 + 1;
  dword_73E8C = v2 + 2;
  if ( pthread_mutex_unlock(&stru_785D0) )
    sub_B50C("unlock_curses", 2930);
  off_72D18();
  sub_19730();
}
