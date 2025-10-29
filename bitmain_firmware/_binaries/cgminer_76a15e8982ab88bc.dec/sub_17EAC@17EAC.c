const char *__fastcall sub_17EAC(int a1)
{
  int v3; // r3

  if ( dword_73E48 )
    return "Use only user + pass or userpass, but not both";
  v3 = dword_73E44 + 1;
  dword_73E44 = v3;
  if ( v3 > dword_77FC0 )
  {
    sub_17974();
    v3 = dword_73E44;
  }
  sub_5858C(a1, (_DWORD *)(*(_DWORD *)(dword_78260 + 4 * (v3 - 1)) + 208));
  return 0;
}
