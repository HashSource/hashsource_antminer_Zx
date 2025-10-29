int __fastcall sub_1FF34(int a1)
{
  int v3; // r4

  if ( *(_DWORD *)(a1 + 132) != 1 )
    return 0;
  if ( dword_73D34 == 4 || dword_73D34 == 3 || *(_BYTE *)(a1 + 664) && *(_BYTE *)(a1 + 129) )
    return 1;
  if ( a1 == sub_1D9A0() )
    return 1;
  if ( *(_DWORD *)(a1 + 756) )
    return 1;
  if ( !dword_73D34 )
  {
    v3 = *(_DWORD *)(a1 + 4);
    if ( v3 < sub_1FAC4() )
      return 1;
  }
  return (unsigned __int8)byte_782F0;
}
