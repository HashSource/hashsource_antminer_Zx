int __fastcall sub_11F70(int a1)
{
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // t1

  if ( dword_77FC0 <= 0 )
    return sub_B288(a1);
  v1 = dword_78260;
  v2 = *(_DWORD *)dword_78260;
  if ( *(_DWORD *)(*(_DWORD *)dword_78260 + 4) != a1 )
  {
    v3 = 0;
    while ( ++v3 != dword_77FC0 )
    {
      v4 = *(_DWORD *)(v1 + 4);
      v1 += 4;
      v2 = v4;
      if ( *(_DWORD *)(v4 + 4) == a1 )
        return v2;
    }
    return sub_B288(a1);
  }
  return v2;
}
