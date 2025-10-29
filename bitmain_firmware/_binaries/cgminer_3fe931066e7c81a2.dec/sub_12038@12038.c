int __fastcall sub_12038(int a1)
{
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // t1

  if ( dword_7B198 <= 0 )
    return sub_B340(a1);
  v1 = dword_7B438;
  v2 = *(_DWORD *)dword_7B438;
  if ( *(_DWORD *)(*(_DWORD *)dword_7B438 + 4) != a1 )
  {
    v3 = 0;
    while ( ++v3 != dword_7B198 )
    {
      v4 = *(_DWORD *)(v1 + 4);
      v1 += 4;
      v2 = v4;
      if ( *(_DWORD *)(v4 + 4) == a1 )
        return v2;
    }
    return sub_B340(a1);
  }
  return v2;
}
