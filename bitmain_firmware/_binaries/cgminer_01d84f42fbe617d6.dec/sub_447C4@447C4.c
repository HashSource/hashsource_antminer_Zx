void __fastcall sub_447C4(int a1, int a2)
{
  int v3; // r0
  int v5; // r2
  int v6; // r2

  v3 = *(_DWORD *)(a1 + 8);
  if ( !v3 || (v5 = *(_DWORD *)(v3 + 4), v5 == -1) || (v6 = v5 - 1, (*(_DWORD *)(v3 + 4) = v6) != 0) )
  {
    *(_DWORD *)(a1 + 8) = a2;
  }
  else
  {
    sub_46C5C((void **)v3);
    *(_DWORD *)(a1 + 8) = a2;
  }
}
