void __fastcall sub_18178(int a1, int a2)
{
  int v2; // r2

  if ( byte_7B940 )
  {
    v2 = dword_77028;
  }
  else
  {
    v2 = dword_7702C;
    a2 = dword_77028;
  }
  if ( !byte_7B940 )
    v2 += a2;
  dword_7701C = v2 + 1;
  dword_77024 = v2 + 2;
  if ( pthread_mutex_unlock(&mutex) )
    sub_B5C4("unlock_curses", 2930);
  off_75ED8();
  sub_18068();
}
