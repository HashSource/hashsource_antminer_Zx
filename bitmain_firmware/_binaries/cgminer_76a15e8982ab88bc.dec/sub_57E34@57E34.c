int __fastcall sub_57E34(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v4; // r0
  char *i; // r4
  int v6; // r5
  int v7; // r0

  if ( !a1 || *a1 || !a2 || *a2 )
    return -1;
  v4 = sub_57254(a2);
  for ( i = (char *)sub_572CC((int)v4); i; i = (char *)sub_572CC(v7) )
  {
    v6 = sub_572D8((int)(i - 16));
    if ( !v6 )
      break;
    if ( sub_571D8(a1, i) )
    {
      if ( *(_DWORD *)(v6 + 4) != -1 )
        ++*(_DWORD *)(v6 + 4);
      sub_57BD8(a1, i, v6);
    }
    v7 = sub_572A0(a2, (int)(i - 16));
  }
  return 0;
}
