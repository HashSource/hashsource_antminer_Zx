int __fastcall sub_5A8A0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v4; // r0
  char *i; // r4
  int v6; // r0
  int v7; // r8

  if ( !a1 || *a1 || !a2 || *a2 )
    return -1;
  v4 = sub_59E9C(a2);
  for ( i = (char *)sub_59F14((int)v4); i; i = (char *)sub_59F14(v6) )
  {
    v7 = sub_59F20((int)(i - 16));
    if ( !v7 )
      break;
    if ( !sub_59E20(a1, i) )
    {
      if ( *(_DWORD *)(v7 + 4) != -1 )
        ++*(_DWORD *)(v7 + 4);
      sub_5A820(a1, i, v7);
    }
    v6 = sub_59EE8(a2, (int)(i - 16));
  }
  return 0;
}
