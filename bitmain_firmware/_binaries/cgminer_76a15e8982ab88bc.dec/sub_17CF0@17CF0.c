int sub_17CF0()
{
  int v0; // r3

  v0 = ++dword_73E4C;
  if ( dword_73E4C > dword_77FC0 )
  {
    sub_17974();
    v0 = dword_73E4C;
  }
  return *(_DWORD *)(dword_78260 + 4 * (v0 - 1));
}
