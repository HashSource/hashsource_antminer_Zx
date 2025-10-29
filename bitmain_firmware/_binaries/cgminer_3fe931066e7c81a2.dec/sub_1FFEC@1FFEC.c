int __fastcall sub_1FFEC(int a1)
{
  int v3; // r4

  if ( *(_DWORD *)(a1 + 132) != 1 )
    return 0;
  if ( dword_76EFC == 4 || dword_76EFC == 3 || *(_BYTE *)(a1 + 664) && *(_BYTE *)(a1 + 129) )
    return 1;
  if ( a1 == sub_1DA58() )
    return 1;
  if ( *(_DWORD *)(a1 + 756) )
    return 1;
  if ( !dword_76EFC )
  {
    v3 = *(_DWORD *)(a1 + 4);
    if ( v3 < sub_1FB7C() )
      return 1;
  }
  return (unsigned __int8)byte_7B4C8;
}
