int sub_17DB8()
{
  int v0; // r3

  v0 = ++dword_77014;
  if ( dword_77014 > dword_7B198 )
  {
    sub_17A3C();
    v0 = dword_77014;
  }
  return *(_DWORD *)(dword_7B438 + 4 * (v0 - 1));
}
