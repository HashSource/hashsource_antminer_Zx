const char *__fastcall sub_17F68(int a1)
{
  int v3; // r3

  if ( dword_77010 )
    return "Use only user + pass or userpass, but not both";
  v3 = dword_7700C + 1;
  dword_7700C = v3;
  if ( v3 > dword_7B198 )
  {
    sub_17A3C();
    v3 = dword_7700C;
  }
  sub_5B1D4(a1, (_DWORD *)(*(_DWORD *)(dword_7B438 + 4 * (v3 - 1)) + 208));
  return 0;
}
