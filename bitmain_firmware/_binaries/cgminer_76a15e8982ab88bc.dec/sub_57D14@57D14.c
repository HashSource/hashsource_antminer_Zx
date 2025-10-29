int __fastcall sub_57D14(_DWORD *a1, char *a2, int a3)
{
  int v7; // r3
  int v8; // r3

  if ( a2 && sub_57044(a2, -1) )
    return sub_57BD8(a1, a2, a3);
  if ( a3 )
  {
    v7 = *(_DWORD *)(a3 + 4);
    if ( v7 != -1 )
    {
      v8 = v7 - 1;
      *(_DWORD *)(a3 + 4) = v8;
      if ( !v8 )
        sub_5779C((void **)a3);
    }
  }
  return -1;
}
